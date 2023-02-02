 #include "Image.h"
 //#include "../lib/cs225/HSLAPixel.h"
 //#include <../lib/cs225/PNG.h>
 #include<iostream>
 void Image::	lighten (){
  lighten(0.1);
 }
    void Image::lighten (double amount){
    
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
          
           cs225::HSLAPixel&  temp = getPixel(i, j);
           
           if ( temp.l + amount >= 1 ){
               temp.l = 1;
               
           } else {
            temp.l += amount;
           }
         }
      }
    }
    void Image::	darken (){
      darken(0.1);
    }
    void Image::	darken (double amount){
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
           cs225::HSLAPixel&  temp = getPixel(i, j);
           if (temp.l - amount <=0 ){
               temp.l = 0;
           } else{
            temp.l -= amount;
           }
         }
      }
    }
    void Image::	saturate (){
      saturate(0.1);
    }
    void Image::	saturate (double amount){
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
          
           cs225::HSLAPixel&  temp = getPixel(i, j);
           
           if ( temp.s + amount >= 1 ){
               temp.s = 1;
               
           }else {
            temp.s += amount;
           }
         }
      }
    }
    void Image::	desaturate (){
      desaturate(0.1);
    }
    void Image::	desaturate (double amount){
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
           cs225::HSLAPixel&  temp = getPixel(i, j);
           if (temp.s - amount <=0 ){
               temp.s = 0;               
           } else {
            temp.s -= amount;
           }
         }
      }
    }
    
    void	Image::grayscale (){
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
           cs225::HSLAPixel&  temp = getPixel(i, j);
           temp.h = 0;
           temp.s = 0;
           temp.l =0;
           temp.a = 0;
         }
      }
    }
    void Image::illinify (){
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
           cs225::HSLAPixel&  temp = getPixel(i, j);
           if (std::abs(temp.h -216) > std::abs(temp.h - 11))  {
            //closer to orange
            if (std::abs(temp.h - 371)> std::abs(temp.h - 216))
              
              temp.h = 216;
            temp.h = 11;

           } else {
            //closer to blue
            temp.h = 216;
           }
         }
      }
    }
    void Image::	scale (double factor){
      //
      scale(factor*width(),factor*height());
    
    }


    void Image::	scale (unsigned w, unsigned h){
       int original_height  = height();
       int original_width  = width();
    
      cs225::PNG old = cs225::PNG(*this);
      
      if (w * original_height != h * original_width){
        // ratio is not equal
         int h1 = h;
         int w1 = w;

         if(abs(h1 - original_height) < abs(w1 - original_width)){
          
          w = (h1*original_width)/original_height;
         }else{
          h = (w1*original_height)/original_width;
         }
      }
      

      resize(w,h);
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j < height(); j++) {
            cs225::HSLAPixel& temp = getPixel(i, j);
            
            temp= old.getPixel(i * original_width/width(),  j * original_height/height());
            
         }
      }
      
    }
    void Image::rotateColor(double degrees){
      for(unsigned int i = 0; i < width();i++){
         for(unsigned int j = 0; j <height();j++) {
           cs225::HSLAPixel&  temp = getPixel(i, j);
           
          while(temp.h + degrees>360 || temp.h+ degrees < 0) {
            if(temp.h + degrees>360 ){
            
              temp.h -=360;

            } else if (temp.h+ degrees < 0){
              temp.h += 360;
            }
          }
          temp.h += degrees;
         }
      }
    }
    