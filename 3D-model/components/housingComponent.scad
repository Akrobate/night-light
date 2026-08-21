use <../pieces/facadeTopPiece.scad>
use <../pieces/facadeBottomPiece.scad>
use <../pieces/housingBorderPiece.scad>

include <../configurations/global.scad>

/**
 * housingComponent
 * @name housingComponent
 * @description housingComponent
 * @type component
 * @parent main
 */
module housingComponent() {

    translate([0, 0, case_external_z_size - case_external_panes_thickness])
        facadeTopPiece();

    translate([0, 0, 0])
        facadeBottomPiece();

    translate([0, 0, case_external_panes_thickness])
        housingBorderPiece();
}


/**
 * @png
 * @colorscheme BeforeDawn
 */
housingComponent();

