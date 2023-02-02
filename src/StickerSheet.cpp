
 #include "../lib/cs225/HSLAPixel.h"
 #include <../lib/cs225/PNG.h>
 #include "Image.h"
#include "StickerSheet.h"
#include<iostream>
#include<vector>
StickerSheet::StickerSheet (const Image &picture, unsigned max){
    base_pic_ = new Image(picture);
    max_ = max;

}
    StickerSheet::	~StickerSheet (){

        for (auto i: vec_image_){
            delete i;
            i =NULL;
        }
        delete base_pic_;
        base_pic_ =NULL;
     }
   StickerSheet:: StickerSheet (const StickerSheet &other){
//StickerSheet::~StickerSheet();
    for(const auto& image: other.vec_image_){
        Image* temp = new Image(*image);
        vec_image_.push_back(temp);

         }
         base_pic_ = new Image(*other.base_pic_);
    max_ = other.max_;

   }
    const StickerSheet &  StickerSheet::operator= (const StickerSheet &other){
        if (&other ==this){
            return *this;
        }
        StickerSheet::~StickerSheet();
       for(const auto image: other.vec_image_){
        Image* temp = new Image(*image);
        vec_image_.push_back(temp);

         }
         base_pic_ = new Image(*other.base_pic_);
    max_ = other.max_;
        return *this;
    }
    void 	StickerSheet::changeMaxStickers (unsigned max){
        if (max_ >max ){
            //lose data
            size_t size = vec_image_.size();
            for (size_t i = 0; i < size;i++){
             
                if (i +1>max) {
                    
                    delete vec_image_.back();
                    vec_image_.back() = NULL;
                    vec_image_.pop_back();
                }
            }
            
        }
        // for(auto image: vec_image_)
        //     std::cout<<"x_:"<< x<<"y_:"<<image->y_<<std::endl;
        //std::cout<<vec_image_.size()<<std::endl;
        max_ = max;
    }
    int 	StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
        if (vec_image_.size() == max_|| x <0|| y <0) {
            return -1;
        }
        Image* temp = new Image(sticker);
        temp->x_ = x;
        temp->y_ = y;
        //new or not?
        vec_image_.push_back(temp);
        
        return (int)vec_image_.size();
    }
    bool 	StickerSheet::translate (unsigned index, unsigned x, unsigned y){
        if (index >= vec_image_.size() || index <0){
            return false;
        }
        vec_image_.at(index)->x_= x;
        vec_image_.at(index)->y_= y;
        return true;
    }
    void 	StickerSheet::removeSticker (unsigned index){
        if (index >= vec_image_.size() || index <0){
            return ;
        }
        if (vec_image_.size() == 0) {
            return;
        }
        delete vec_image_[index];
        vec_image_[index]= NULL;
        vec_image_.erase(vec_image_.begin()+index);
        //std::cout<<vec_image_.size()<<std::endl;
    }
    Image * StickerSheet::getSticker (unsigned index){
        if (index >= vec_image_.size() || index <0){
            return NULL;
        }
        return vec_image_.at(index);
    }
    Image 	StickerSheet::render () const{
        Image new_picture = Image(*base_pic_);
        for (const auto image: vec_image_){

        unsigned int base_width= new_picture.width();
        unsigned int base_height= new_picture.height();
        unsigned int x = image->x_;
        unsigned int y = image->y_;

         if (x + image->width()> base_width){
            if (x <= base_width){
                //x in bound
                new_picture.resize(image->width()+x,base_height);
            } else {
                //x y out of bound
                new_picture.resize(base_width + image->width()+x,base_height);
            }
         }



           if (y + image->height()> base_height){
            if (y<= base_height){
                new_picture.resize(base_width,  image->height()+y);
            }else {
                new_picture.resize(base_width, base_height + image->height()+y);
            }
           } 
            
            
            
            
            
            for (unsigned   int i = 0 ; i < image->width();i++){
                for(unsigned  int  j = 0; j < image->height();j++){
                    
                    
                      auto& temp  = new_picture.getPixel(i+x, j+image->y_);
                      if (image->getPixel(i,j).a != 0){
                        temp = image->getPixel(i,j);
                      }
                }
            }
        }
        
        
        return new_picture;    }
    