use <./components/housing-component.scad>
use <./pieces/crystalPiece.scad>
// use <./openscad_modules/esp-module-holder-3d-model/components/holder-8266-D1-component.scad>
include <./configurations/global.scad>


// holder8266D1Component();


housingComponent();

translate([
    case_external_x_size / 2,
    case_external_y_size / 2,
    case_external_z_size
])
    crystalPiece();

