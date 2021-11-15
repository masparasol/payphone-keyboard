



// outer square dimensions
os=18.3;

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


