
module crystal(scale_all) {

    function generateSeedArray(seed) = [for(i = [1:25]) rands(0, 1000, 7, seed * i)];

    seed_data = generateSeedArray(655);

    scale(scale_all)
        crystalrock();

    module crystalrock(){
        union(){
            semisphere(5, $fn=6);
            for(i = [1:25]){
                angleX = 40;
                angleY = 40;

                g1 = randomInt(-angleX, angleX, seed_data[i - 1][0]);
                g2 = randomInt(-angleY, angleY, seed_data[i - 1][1]);
            
                lados = 6; 
                radio1 = randomInt(1, 2, seed_data[i - 1][2]);
                radio2 = randomInt(1.1, 1.6, seed_data[i - 1][3]) * radio1;
                radio3 = randomInt(0, 0.5, seed_data[i - 1][4]) * radio2;

                altura = radio1 * randomInt(1, 2, seed_data[i - 1][5]) * 5 * (0.5 + pow((abs(cos(g1) * cos(g2))), 4));
                pico = randomInt(0.1, 0.3, seed_data[i - 1][6]) * altura;    
            
                rotate([g1, g2, 0])
                    translate([0, 0, 3])
                        crystal(lados, radio1, radio2, radio3, altura, pico);
            }
        }
    }

    /**
    * min_value: Minimum value of random number range
    * max_value: Maximum value of random number range
    * value_count: Number of random numbers to return as a vector
    * seed_value (optional)
    */
    function randomInt(min_value, max_value, seed) = rands(min_value, max_value, 1, seed)[0];


    module crystal(lados, radio1, radio2, radio3, altura, pico){
        cylinder(r1 = radio1, r2 = radio2, h = altura,$fn = lados);
        translate([0, 0, altura])
            cylinder(r1 = radio2, r2 = radio3, h = pico, $fn = lados);
    }

    module semisphere(r){
        difference(){
            sphere(r); 
            translate([0, 0, -r])
                cube([2 * r, 2 * r, 2 * r], center = true);
        }
    }

}


crystal();
