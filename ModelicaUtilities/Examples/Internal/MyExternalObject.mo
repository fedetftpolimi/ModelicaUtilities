within ModelicaUtilities.Examples.Internal;
class MyExternalObject
  extends ExternalObject;

  function constructor

    output MyExternalObject externalObject;

    external "C" externalObject = MyExternalObject_create(ModelicaUtilities.callbacks) annotation (
      Library={"MyExternalLibrary"});

  end constructor;

  function destructor

    input MyExternalObject externalObject;

  external "C" MyExternalObject_free(externalObject) annotation (
      Library={"MyExternalLibrary"});

  end destructor;

  annotation(Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100,-100},{100,100}}), graphics={
          Rectangle(
            lineColor={160,160,164},
            fillColor={160,160,164},
            fillPattern=FillPattern.Solid,
            extent={{-100.0,-100.0},{100.0,100.0}},
            radius=25.0)}));
end MyExternalObject;
