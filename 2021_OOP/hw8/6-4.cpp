Complex& Complex::operator+(Complex & com){
     com.imgPart=com.imgPart+this->imgPart;
     com.realPart=com.realPart+this->realPart;
     return com;
}