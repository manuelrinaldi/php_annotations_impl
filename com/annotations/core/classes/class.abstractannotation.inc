<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 04/12/2016
 * Time: 23:52
 */

require_once "com/annotations/core/interfaces/interface.annotation.inc";
require_once "com/annotations/core/traits/trait.annotationhelper.inc";

class AbstractAnnotation implements IAnnotation
{
    use AnnotationHelper;
}