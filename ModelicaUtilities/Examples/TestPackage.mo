within ModelicaUtilities.Examples;

package TestPackage
  extends Modelica.Icons.Package;
  model PackageConstantExample
    extends Modelica.Icons.Example;
    Real yy = y;
  equation
  
    annotation(
      Icon(coordinateSystem(preserveAspectRatio = false)),
      Diagram(coordinateSystem(preserveAspectRatio = false)));
  end PackageConstantExample;

constant Real y=ModelicaUtilities.Examples.Internal.MyExternalFunction(1);

end TestPackage;