include <./../configurations/global.scad>
use <./../libraries/commons.scad>

use <./subpieces/rounded-pane.scad>


module facadeFront(
    x_size = case_external_x_size,
    y_size = case_external_y_size,
    z_size = case_external_panes_thickness,

    throws_margin = facade_throws_margin,

    round_edges_radius = facade_front_round_edges_radius,

    $fn = facade_fn
) {

    difference() {
        color("BurlyWood")
            roundedPane(
                [x_size, y_size, z_size],
                r1 = round_edges_radius,
                r2 = round_edges_radius,
                center = false,
                $fn = $fn
            );

        translate([0, 0, -z_size / 2])
            forEachCoord([
                [throws_margin, throws_margin],
                [x_size - throws_margin, throws_margin],
                [throws_margin, y_size - throws_margin],
                [x_size - throws_margin, y_size - throws_margin,],
            ])
                cylinder(h = z_size * 2, d = 3, $fn = $fn);

    }
}

%facadeFront();

