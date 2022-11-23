#include <stdio.h>
int isIntersecting = 0;

struct region{
    int xEsq, yInf, xDir, ySup;
};

struct region preserv_region, tempRegion;


void detectIntersection(struct region reg){
    if(
        ((reg.xEsq >= preserv_region.xEsq && reg.xEsq <= preserv_region.xDir) || (reg.xDir <= preserv_region.xDir && reg.xDir >= preserv_region.xEsq)) && ((reg.yInf >= preserv_region.yInf && reg.yInf <= preserv_region.ySup) || (reg.ySup <= preserv_region.ySup && reg.ySup >= preserv_region.yInf) /* Tinha uma comparação maior n, doido? */)){
        isIntersecting = 1;
    }
}

int main(){
    int regions;
    scanf("%d %d %d %d", &preserv_region.xEsq, &preserv_region.yInf, &preserv_region.xDir, &preserv_region.ySup);
    scanf("%d", &regions);

    for (int i = 0; i < regions; ++i) {
        scanf("%d %d %d %d ", &tempRegion.xEsq, &tempRegion.yInf, &tempRegion.xDir, &tempRegion.ySup);
        detectIntersection(tempRegion);
    }
    printf("%d",isIntersecting);
    return 0;
}
