<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 04/12/2016
 * Time: 23:57
 */


define("ANNOTATION", "annotation");

trait AnnotationUtilities
{

    /**
     * @param $n
     * @return string
     */
    private function documentationFormatter($n)
    {
        $value = trim(substr(trim($n), 1, strlen($n)));
        return $value;
    }

    /**
     * @param $n
     * @return bool
     */
    private function getAnnotations($n){
        return !(strpos(strtolower($n), ANNOTATION) === false);
    }

    /**
     * @param $n
     * @return null
     */
    private function prepare($n)
    {
        $array = explode(" ", $n, 3);
        $className = ucfirst(strtolower($array[1])).ucfirst(ANNOTATION);
        if(class_exists($className)):
            $params = trim($array[2]);
            $params = trim(substr($params, 1, strlen($params) -2));
            $params = explode(",", $params);
            $object = new $className();
            foreach($params as $key => $value):
                $variables = explode("=", trim($value));
                $methodName = trim($variables[0]);
                $methodValue = trim($variables[1]);
                $funcGet = function () use ($methodName) { return $this->__get($methodName); };
                $object->__attach($methodName, 'get' . ucfirst($methodName), $funcGet);
                $funcSet = function () use ($methodName, $methodValue) { $this->$methodName = $methodValue; };
                $setMethod = 'set' . ucfirst($methodName);
                $object->__attach($methodName, 'set' . ucfirst($methodName), $funcSet);
                $object->$setMethod();
            endforeach;
            return $object;
        endif;
        return null;
    }

    /**
     * @param $n
     * @return bool
     */
    private function removeDeadLeaf($n)
    {
        return !is_null($n);
    }

    /**
     * @param $doc
     * @return array|null
     */
    private function elaborateDocumentation($doc)
    {
        $annotations = explode("\n", $doc);
        $annotations = array_map(function($n) { return $this->documentationFormatter($n); }, $annotations);
        $annotations = array_filter($annotations, function($n) { return $this->getAnnotations($n); } ) ;
        $annotations = array_filter(array_map(function($n){ return $this->prepare($n); }, $annotations), function($n) { return $this->removeDeadLeaf($n); });
        return (empty($annotations)) ? null : array_values($annotations);
    }
}