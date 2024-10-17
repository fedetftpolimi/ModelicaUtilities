within ModelicaUtilities.Examples;

model PackageConstantExample
  extends Modelica.Icons.Example;
  
  constant Real y=ModelicaUtilities.Examples.Internal.MyExternalFunction(1);
  
equation

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end PackageConstantExample;