<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 04/12/2016
 * Time: 23:55
 */

interface IAnnotationsFetcher
{

    public function getAnnotationsForClass($className);
    public function getAnnotationsForMethod($className, $methodName);
    public function getAnnotationsFroProperty($className, $paramName);
}