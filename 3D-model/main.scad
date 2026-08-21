use <components/housingComponent.scad>
use <pieces/crystalPiece.scad>
use <assets/esp8266WemosD1.scad>

include <configurations/global.scad>

HOUSING_V2 = true;


module main() {

    if (HOUSING_V2) {
        housingComponent();
    } else {
        housingComponent();
    }

    translate([
        case_external_x_size / 2,
        case_external_y_size / 2,
        case_external_z_size
    ])
        crystalPiece();

    esp8266WemosD1();
}


/**
 * @png
 * @colorscheme BeforeDawn
 */
main();
