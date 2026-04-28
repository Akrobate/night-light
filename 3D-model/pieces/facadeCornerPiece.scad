include <../configurations/global.scad>
use <../openscad_modules/housing/facadeCorner.scad>

/**
 * facadeCornerPiece
 * @name facadeCornerPiece
 * @description
 * @type piece
 * @parent housingComponent
 */
module facadeCornerPiece(
    round_radius = facade_front_round_edges_radius,
    z_size = case_external_z_size - (case_external_panes_thickness * 2),
    main_x_size = facade_corners_main_x_size,
    main_y_size = facade_corners_main_y_size,
    main_thickness = facade_corners_main_thickness,

    offset_thickness = case_external_panes_thickness,
    offset_lenght = facade_corners_offset_lenght,

    correction_offset_thickness = 0.0, //
    correction_offset_length = 0.0, //

    throw_diameter = insert_throw_diameter,
    throw_depth = insert_throw_length,
    throw_x_margin = facade_throws_margin,
    throw_y_margin = facade_throws_margin,
    throw_z_margin = facade_throws_margin,
    $fn = facade_fn
) {
    facadeCorner(
        round_radius = round_radius,
        z_size = z_size,
        main_x_size = main_x_size,
        main_y_size = main_y_size,
        main_thickness = main_thickness,

        x_branch_offset_thickness = offset_thickness,
        x_branch_offset_lenght = offset_lenght,

        y_branch_offset_thickness = offset_thickness,
        y_branch_offset_lenght = offset_lenght,

        correction_offset_thickness = correction_offset_thickness,
        correction_offset_length = correction_offset_length,

        throw_diameter = throw_diameter,
        throw_depth = throw_depth,
        throw_x_margin = throw_x_margin,
        throw_y_margin = throw_y_margin,
        throw_z_margin = throw_z_margin
    );
}


/**
 * @stl
 * @png
 * @colorscheme BeforeDawn
 * @view axes,scales
 */
facadeCornerPiece(
    $fn = 100
);