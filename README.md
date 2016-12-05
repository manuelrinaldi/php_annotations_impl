# php_annotations_impl
Support for custom annotation in php


<h1>PHP ANNOTATIONS</h1>

This few but powerfull classes allow you to create your custom annotations and use them
in the runtime envoirment like key => value objects.

The possibilities are a lot!! which include: 

Mapping variables with database fields to dynamically fill the model object without to 
create a method for each table or query.

Generating runtime dynamically classes in runtime to provide injection like Dagger framework is doing in java or android.

Many others only your mind is your limit!!

Here is an example 

<code>
<pre>
  class DatabaseField extends AbstractAnnotation
  {
    <var>protected $type;</var>
    <var>protected $name;</var>
    <var>protected $default;</var>
  }

  class UserModel
  {
    /**
    * @Annotation DatabaseField {type=string, name=usr_firstname, default=pippo}
    */
    private $name;
    
    public function setName($value)
    {
      $this->name = $value;
    }
  }
  
  class DatabaseReader
  {
    public function getData()
    {
      $fetcher = new AnnotationsFetcher();
      $databaseFields = $fetcher->getAnnotationsForProperty("UserModel", "name");
      $nameField = $databaseFields[0];
      $sql = "SELECT $nameField->getName() FROM users where usr_id = 10";
      $rs = $db->exec();
      $user = new UserModel();
      $user->setName($rs[$nameField->getName()]); 
    }
  }

</pre>
</code>


Still need some imporvements but the potential of Annotations is big!!

Any interested in helping to make it better is welcome!!

