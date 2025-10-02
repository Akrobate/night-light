
module crystal(
    scale_all = 1,
    angle_x = 40,
    angle_y = 40,
    count = 25,
    seed = 655
) {

    function generateSeedArray(_seed) = [for(i = [1 : count]) rands(0, 1000, 7, _seed * i)];

    seed_data = generateSeedArray(seed);

    scale(scale_all)
        crystalrock($fn = $fn);

    module crystalrock(){
        union(){
            // semisphere(5, $fn=5);
            support_cylinder(5, $fn=5);
            echo("crystalrock FN", $fn)
            for(i = [1 : count]){
                angle_x = 40;
                angle_y = 40;

                g1 = randomInt(-angle_x, angle_x, seed_data[i - 1][0]);
                g2 = randomInt(-angle_y, angle_y, seed_data[i - 1][1]);
            
                lados = 6; 
                radio1 = randomInt(1, 2, seed_data[i - 1][2]);
                radio2 = randomInt(1.1, 1.6, seed_data[i - 1][3]) * radio1;
                radio3 = randomInt(0, 0.5, seed_data[i - 1][4]) * radio2;

                height = radio1 * randomInt(1, 2, seed_data[i - 1][5]) * 5 * (0.5 + pow((abs(cos(g1) * cos(g2))), 4));
                pico = randomInt(0.1, 0.3, seed_data[i - 1][6]) * height;    
            
                rotate([g1, g2, 0])
                    translate([0, 0, 3])
                        crystal(lados, radio1, radio2, radio3, height, pico);
            }
        }
    }

    function randomInt(min_value, max_value, seed) = rands(min_value, max_value, 1, seed)[0];

    module crystal(lados, radio1, radio2, radio3, height, pico){
        cylinder(r1 = radio1, r2 = radio2, h = height,$fn = lados);
        translate([0, 0, height])
            cylinder(r1 = radio2, r2 = radio3, h = pico, $fn = lados);
    }

    module semisphere(r) {
        echo("semisphere FN", $fn)
        difference(){
            sphere(r); 
            translate([0, 0, -r])
                cube([2 * r, 2 * r, 2 * r], center = true);
        }
    }

    module support_cylinder(r) {
        cylinder(h = 2, r = r);
    }

}


crystal(
    $fn = 150
);
