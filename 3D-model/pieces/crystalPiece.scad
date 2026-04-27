use <../libraries/crystal.scad>


/**
 * crystalPiece
 * @name crystalPiece
 * @description
 * @type piece
 * @parent housingComponent
 */
module crystalPiece() {
    crystal(scale_all = 4);
}


/**
 * @stl
 * @png
 * @colorscheme BeforeDawn
 * @view axes,scales
 */
crystalPiece();
