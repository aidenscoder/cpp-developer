struct point {
    float x; 
    float y;
    float (*sum)(struct point self);
};

float sum(struct point self){
    return self.x+self.y;
}

struct point Point(float x, float y){
    struct point returner = {x,y,sum};
    return returner;
}

int main(){
    struct point mpoint = Point(10,20);
    mpoint.sum(mpoint);
    return 0;
}