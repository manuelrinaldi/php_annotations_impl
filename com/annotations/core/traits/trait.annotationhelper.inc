<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 04/12/2016
 * Time: 23:47
 */
trait AnnotationHelper
{
    protected $methods = [];

    /**
     * @param $param
     * @param $name
     * @param $method
     *
     * Create a new method to the annotation class
     */
    public function __attach($param, $name, $method)
    {
        if(property_exists(get_called_class(), $param)){
            $binded = Closure::bind($method, $this, get_called_class());
            $this->methods[$name] = $binded;
        }
    }//end function

    /**
     * @param $name
     * @param $arguments
     * @return mixed
     *
     * Is in charge to let the object call the dynamics method added to the class
     */
    public function __call($name , $arguments)
    {
        if(array_key_exists($name, $this->methods))
        {
            return call_user_func_array($this->methods[$name] , $arguments);
        }
    }//end function

    /**
     * @param $name
     * @return mixed
     *
     * Return the value of the fields created in the Annotation Class
     */
    public function __get($name){
        return $this->$name;
    }//end function
}