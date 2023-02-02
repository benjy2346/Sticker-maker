#pragma once

#include <../lib/cs225/PNG.h>

/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

class Image : public cs225::PNG{
    public:
    void 	lighten ();
    void 	lighten (double amount);
    void 	darken (double amount);
    void 	darken ();
    void 	saturate ();
    void 	saturate (double amount);
    void 	desaturate ();
    void 	desaturate (double amount);
    void    rotateColor (double degrees);
    void	grayscale ();
    void    illinify ();
    void 	scale (double factor);
    void 	scale (unsigned w, unsigned h);
   
    
    Image(){};

    

    unsigned int x_;
    unsigned int y_;

};
