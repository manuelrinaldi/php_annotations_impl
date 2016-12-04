<?php

/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 05/12/2016
 * Time: 00:11
 */

require_once "com/annotations/core/classes/class.abstractannotation.inc";

class ClassAnnotation extends AbstractAnnotation
{

    protected $type;
    protected $name;
    protected $visibility;
}