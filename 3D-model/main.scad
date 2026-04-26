use <components/housingComponent.scad>
use <pieces/crystalPiece.scad>

include <configurations/global.scad>

// holder8266D1Component();


housingComponent();

translate([
    case_external_x_size / 2,
    case_external_y_size / 2,
    case_external_z_size
])
    crystalPiece();

