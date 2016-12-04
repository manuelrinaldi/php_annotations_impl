<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 04/12/2016
 * Time: 23:54
 */

require_once "com/annotations/core/interfaces/interface.annotationsfetcher.inc";
require_once "com/annotations/core/traits/trait.annotationutilities.inc";

class AnnotationsFetcher implements IAnnotationsFetcher
{
    use AnnotationUtilities;


    /**
     * @param $className
     * @return array|null
     *
     * Search for documentation in classes
     */
    public function getAnnotationsForClass($className)
    {
        if(class_exists($className) || trait_exists($className) || interface_exists($className)):
            $reflection = new ReflectionClass($className);
            return $this->start($reflection);
        else:
            throw new UnexpectedValueException("The class you specified doesn't exist");
        endif;
    }//end function

    /**
     * @param $className
     * @param $methodName
     * @return array|null
     *
     * Search for documentation in methods
     */
    public function getAnnotationsForMethod($className, $methodName)
    {
        if(class_exists($className) || trait_exists($className) || interface_exists($className))
        {
            if(method_exists($className, $methodName)):
                $reflection = new ReflectionMethod($className."::".$methodName);
                return $this->start($reflection);
            else:
                throw new BadMethodCallException("method in class doesn't exist");
            endif;
        }else{
            throw new UnexpectedValueException("class in parameter doesn't exist");
        }
    }

    /**
     * @param $className
     * @param $paramName
     * @return array|null
     *
     * Search for documentation in properties
     */
    public function getAnnotationsFroProperty($className, $paramName)
    {
        if(class_exists($className))
        {
            if(property_exists($className, $paramName)):
                $reflection = new ReflectionProperty($className, $paramName);
                return $this->start($reflection);
            else:
                throw new UnexpectedValueException("param in class doesn't exist");
            endif;
        }else{
            throw new UnexpectedValueException("class in parameter doesn't exist");
        }
    }

    /**
     * @param $reflection
     * @return array|null
     */
    private function start($reflection)
    {
        return $this->elaborateDocumentation($reflection->getDocComment());
    }
}