<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 04/12/2016
 * Time: 23:45
 */

/**
 * Interface Annotation
 * Base for the annotation solution
 */
interface IAnnotation
{
    public function __attach($param, $name, $method);
    public function __call($method, $arguments);
    public function __get($name);
}