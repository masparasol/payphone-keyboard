// outer square dimensions
os=18.3;

// the thickness of the interior button walls. 
wall_width=1.40;


// This is the "outer square" for a grid of buttons that respects
// the wall_width between each button.
grid_os=(os - wall_width);

//  TOP VIEW OF KEY BUTTON
// ==================================================
//
//  *-----------------*  --.
//   \-----[   ]-----/    |      <--- top right corner ("dips in")
//   |---------------|    |
//   |---------------|    |
//   |---------------|     > 13.60 mm
//   |---------------|    |
//   |---------------|    |
//   /---------------\    |
//  *-----------------*  --.
//
//  |                 |
//  .--------v--------.
//        13.75 mm

under_lip_width=13.75;
under_lip_height=13.60;
under_lip_depth=1; // the clips "snap" onto this.


// ==================================================
//
//
//  . . . -----------------._      ---\
//                           \         |
//                           |          >  2.30 mm
//                          _|         |
//                         |     -----/
//                         |
//                         |
//                         |
//                         |   <--- what we want to "fill in" on the upper layer
//
//  \_. . ._______________/
//             v
//          13.75 mm

lip_height=15.05;
lip_width=15.05;
wall_height=3;
dip_height=2.3;

grid_columns=3;
grid_rows=4;

// point that's center to the grid on the columns
center_x = ((grid_os * grid_columns - 1) / 2);
center_y =((grid_os * grid_rows - 1) / 2);


grid_without_border_width=(grid_os * grid_columns);
grid_without_border_height=(grid_os * grid_rows);

// This adds a "border shim" around the entire grid so it fits flush with
// the phone we're working with.

extra_border_padding=1.5;
border_width=((wall_width / 2) + extra_border_padding);

translate([ border_width, border_width, 0 ])
union() {
        
    for (offset_x=[0:grid_os:(grid_os * grid_columns - 1)]) {
        for (offset_y=[0:grid_os:(grid_os * grid_rows - 1)]) {
            translate([ offset_x, offset_y ]) union() {
                difference() {
                    cube([ os, os, under_lip_depth ]);
                    translate([ (os - under_lip_width) / 2, (os - under_lip_height) / 2, 0 ]) {
                        cube([ under_lip_width, under_lip_height, under_lip_depth ]);
                    }
                }

                translate([ 0, 0, under_lip_depth ]) difference() {
                    cube([ os, os, wall_height ]);
                    
                    translate([ (os - under_lip_width) / 2, (os - under_lip_height) / 2, 0 ]) {
                        cube([ under_lip_width, under_lip_height, wall_height ]);
                    };
                    
                    translate([ (os - lip_width) / 2, (os - lip_height) / 2, 0 ]) {
                        cube([ lip_width, dip_height, wall_height ]);
                    };
                    
                    translate([0, lip_height - dip_height, 0]) 
                    translate([ (os - lip_width) / 2, (os - lip_height) / 2, 0 ]) {
                        cube([ lip_width, dip_height, wall_height ]);
                    };
                    
                }
            }
        }
    }
}


//-----------------------------------------------------------
// This is the border around the grid
difference() {
    cube([ 
        grid_without_border_width + (border_width * 2), 
        grid_without_border_height + (border_width * 2),
        (wall_height + 1) 
    ]);
    
    // This is the size of the grid as a solid cube
    translate([ border_width, border_width, 0 ])
    cube([ grid_without_border_width, grid_without_border_height, wall_height + 1 ]);
}

// This is the border around the grid
* difference() {
    translate([ 
        (border_width) * -1, 
        (border_width) * -1,
        0
    ]) cube([ 
        (grid_os * grid_columns) + wall_width + (extra_border_padding * 2), 
        (grid_os * grid_rows) + wall_width + (extra_border_padding * 2), 
        (wall_height + 1) 
    ]);
    
    // This is the size of the grid as a solid cube
    cube([ grid_os * grid_columns, grid_os * grid_rows, wall_height + 1 ]);
}


//-----------------------------------------------------------------------------
// This adds the "wings" that pop out and catch the bolt
// that secures this print to the phone istelf. 


wing_height=20;
wing_width_from_grid_edge_to_outer_edge=13;
wing_outer_edge_width=2;


outer_edge_to_inner_bolt_interior=5.7;
bolt_diameter=3.4;
bolt_radius=bolt_diameter/2;

translate([ 0, 0, wall_height + under_lip_depth ])
mirror([ 0, 0, 1 ])
translate([ 0, center_y, 0 ])
translate([ 0, wall_width * 2, 0 ])
union() {
    // LEFT WING (center)
    translate([ -1 * wing_width_from_grid_edge_to_outer_edge, -1 * (wing_height / 2), 0 ])
    difference() {
              cube([ 
                wing_width_from_grid_edge_to_outer_edge, 
                wing_height,
                wall_height + under_lip_depth
              ]);
        
            cube([
                outer_edge_to_inner_bolt_interior, 
                wing_height,
                wall_height
            ]);  
     
        translate([ 1.2 + bolt_radius, (wing_height / 2) + 0.4, 0 ]) // 0.2 "centers" bolt hole #lazy
            cylinder (h = wall_height * 100, r=bolt_radius, center = true, $fn=100);     
    }
    
    // LEFT WING (top)
    translate([ 0, wing_height + wall_width, 0 ])
    translate([ -1 * wing_width_from_grid_edge_to_outer_edge, -1 * (wing_height / 2), 0 ])
    difference() {
              cube([ 
                wing_width_from_grid_edge_to_outer_edge, 
                wing_height,
                wall_height + under_lip_depth
              ]);
        
            cube([
                outer_edge_to_inner_bolt_interior, 
                wing_height,
                wall_height
            ]);      
    }
    
     // LEFT WING (top)
    translate([ 0, -1 * (wing_height + wall_width), 0 ])
    translate([ -1 * wing_width_from_grid_edge_to_outer_edge, -1 * (wing_height / 2), 0 ])
    difference() {
              cube([ 
                wing_width_from_grid_edge_to_outer_edge, 
                wing_height,
                wall_height + under_lip_depth
              ]);
        
            cube([
                outer_edge_to_inner_bolt_interior, 
                wing_height,
                wall_height
            ]);      
    }
}


// RIGHT Wing
translate([ 0, 0, wall_height + under_lip_depth ])
mirror([ 0, 0, 1 ])
translate([ (border_width * 2) + grid_without_border_width, 0, 0 ])
mirror([ 1, 0, 0 ])
translate([ 0, center_y, 0 ])
translate([ 0, wall_width * 2, 0 ])
union() {

    translate([ -1 * wing_width_from_grid_edge_to_outer_edge, -1 * (wing_height / 2), 0 ])
    difference() {
              cube([ 
                wing_width_from_grid_edge_to_outer_edge, 
                wing_height,
                wall_height + under_lip_depth
              ]);
        
            cube([
                outer_edge_to_inner_bolt_interior, 
                wing_height,
                wall_height
            ]);  
  
        translate([ 1.2 + bolt_radius, (wing_height / 2) + 0.4, 0 ]) // 0.2 "centers" bolt hole #lazy
            cylinder (h = wall_height * 100, r=bolt_radius, center = true, $fn=100);        
    }
    
    translate([ 0, wing_height + wall_width, 0 ])
    translate([ -1 * wing_width_from_grid_edge_to_outer_edge, -1 * (wing_height / 2), 0 ])
    difference() {
              cube([ 
                wing_width_from_grid_edge_to_outer_edge, 
                wing_height,
                wall_height + under_lip_depth
              ]);
        
            cube([
                outer_edge_to_inner_bolt_interior, 
                wing_height,
                wall_height
            ]);      
    }
    
    translate([ 0, -1 * (wing_height + wall_width), 0 ])
    translate([ -1 * wing_width_from_grid_edge_to_outer_edge, -1 * (wing_height / 2), 0 ])
    difference() {
              cube([ 
                wing_width_from_grid_edge_to_outer_edge, 
                wing_height,
                wall_height + under_lip_depth
              ]);
        
            cube([
                outer_edge_to_inner_bolt_interior, 
                wing_height,
                wall_height
            ]);   
    }
}

