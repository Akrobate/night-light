include <../configurations/global.scad>

use <../libraries/crystal.scad>


/**
 * crystalPiece
 * @name crystalPiece
 * @description
 * @type piece
 * @parent housingComponent
 */
module crystalPiece() {
    crystal(scale_all = crystal_scale_all);
}


/**
 * @stl
 * @png
 * @colorscheme BeforeDawn
 * @view axes,scales
 */
crystalPiece();
