<?php
/**
 * Created by IntelliJ IDEA.
 * User: manuel
 * Date: 05/12/2016
 * Time: 00:14
 */

require_once "com/annotations/core/classes/class.annotationsfetcher.inc";
require_once "com/annotations/core/classes/annotations/class.classannotation.inc";
require_once "com/annotations/core/classes/annotations/class.methodannotation.inc";
require_once "com/annotations/core/classes/annotations/class.paramannotation.inc";


/**
 * @Annotation Class {type=interface}
 */
interface TestA {
    public function sayHello();
}

/**
 * @Annotation Class {type=trait}
 */
trait TestB{

    /**
     * @Annotation Method {name = sayHello, visibility = public}
     */
    public function sayHello(){
        echo "Hello World";
    }
}

/**
 * @Annotation Class {type=class}
 */
class TestC implements TestA{
    use TestB;

    /**
     * @Annotation Param {name=test, type=string, lengthMax=25, default=prova}
     */
    private $test = "prova";
}


$fetcher = new AnnotationsFetcher();
$annotationsTestA = $fetcher->getAnnotationsForClass("TestA");
$annotationsMethodSayHello = $fetcher->getAnnotationsForMethod("TestB", "sayHello");
$annotationsPropertyTest = $fetcher->getAnnotationsFroProperty("TestC", "test");
$objAnn = $annotationsTestA[0];
var_dump($objAnn);
echo "Class Annotation => " . $objAnn->__get("type") . " " . $objAnn->getName() . " " . $objAnn->getVisibility() . "\n";
$objAnn = $annotationsMethodSayHello[0];
echo "Method Annotation => " . $objAnn->getName() . " "  . $objAnn->getVisibility() . "\n";
$objAnn = $annotationsPropertyTest[0];
var_dump($objAnn);
echo "Param Annotation => " . $objAnn->getName() . " " . $objAnn->getLengthMax() . " " . $objAnn->getDefault() . "\n";

