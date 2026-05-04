include <../configurations/global.scad>

use <../openscad_modules/housing/housingBorder.scad>


module housingBorderPiece() {
    housingBorder(
        x_size = case_external_x_size,
        y_size = case_external_y_size,
        z_size = case_external_z_size - case_external_panes_thickness * 2,
        round_edges_radius = facade_front_round_edges_radius,
        border_thickness = case_border_panes_thickness,
        insert_throw_diameter = 4.25,
        insert_throw_length = 6,
        insert_holder_diameter = 10,
        facade_throws_margin = facade_throws_margin,
        _fn = 100
    );
}


housingBorderPiece();

