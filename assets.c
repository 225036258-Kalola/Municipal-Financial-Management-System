#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset()
{
    if(assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full!\n");
        return;
    }

    printf("\nEnter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);

    getchar();

    printf("Enter Asset Name: ");
    fgets(assets[assetCount].assetName, sizeof(assets[assetCount].assetName), stdin);
    assets[assetCount].assetName[strcspn(assets[assetCount].assetName, "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].assetType, sizeof(assets[assetCount].assetType), stdin);
    assets[assetCount].assetType[strcspn(assets[assetCount].assetType, "\n")] = '\0';

    do
    {
        printf("Enter Purchase Value: ");
        scanf("%f", &assets[assetCount].purchaseValue);

        if(assets[assetCount].purchaseValue < 0)
        {
            printf("Purchase value cannot be negative!\n");
        }

    } while(assets[assetCount].purchaseValue < 0);

    getchar();

    printf("Enter Department: ");
    fgets(assets[assetCount].department, sizeof(assets[assetCount].department), stdin);
    assets[assetCount].department[strcspn(assets[assetCount].department, "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(assets[assetCount].condition, sizeof(assets[assetCount].condition), stdin);
    assets[assetCount].condition[strcspn(assets[assetCount].condition, "\n")] = '\0';

    assetCount++;

    printf("\nAsset added successfully!\n");
}

void displayAssets()
{
    int i;

    if(assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\n========== ASSET REGISTER ==========\n");

    for(i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("Asset ID       : %d\n", assets[i].assetID);
        printf("Asset Name     : %s\n", assets[i].assetName);
        printf("Asset Type     : %s\n", assets[i].assetType);
        printf("Purchase Value : N$ %.2f\n", assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
    }
}

void searchAsset()
{
    int searchID;
    int i;
    int found = 0;

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &searchID);

    for(i = 0; i < assetCount; i++)
    {
        if(assets[i].assetID == searchID)
        {
            printf("\nAsset Found!\n");
            printf("Asset ID       : %d\n", assets[i].assetID);
            printf("Asset Name     : %s\n", assets[i].assetName);
            printf("Asset Type     : %s\n", assets[i].assetType);
            printf("Purchase Value : N$ %.2f\n", assets[i].purchaseValue);
            printf("Department     : %s\n", assets[i].department);
            printf("Condition      : %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nAsset not found.\n");
    }
}
