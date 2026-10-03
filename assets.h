#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int assetID;
    char assetName[50];
    char assetType[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

void addAsset();
void displayAssets();
void searchAsset();

#endif
