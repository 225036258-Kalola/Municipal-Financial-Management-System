#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

/* ---------- Input helpers ---------- */

static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Reads a whole line safely and strips the newline */
static void readLine(const char *prompt, char *buf, size_t size)
{
    printf("%s", prompt);

    if (fgets(buf, (int)size, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }

    if (strchr(buf, '\n') == NULL)
    {
        clearInputBuffer();   /* discard overflow if input was too long */
    }

    buf[strcspn(buf, "\n")] = '\0';
}

/* Reads an int, re-prompting until the input is valid */
static int readInt(const char *prompt)
{
    int value;
    int result;

    printf("%s", prompt);

    while ((result = scanf("%d", &value)) != 1)
    {
        if (result == EOF)
        {
            exit(0);
        }
        clearInputBuffer();
        printf("Invalid input. Enter a whole number: ");
    }

    clearInputBuffer();
    return value;
}

/* Reads a non-negative number, re-prompting until valid */
static double readNonNegativeDouble(const char *prompt)
{
    double value;
    int result;

    for (;;)
    {
        printf("%s", prompt);
        result = scanf("%lf", &value);

        if (result == EOF)
        {
            exit(0);
        }

        clearInputBuffer();

        if (result != 1)
        {
            printf("Please enter a number.\n");
        }
        else if (value < 0)
        {
            printf("Purchase value cannot be negative!\n");
        }
        else
        {
            return value;
        }
    }
}

/* ---------- Asset helpers ---------- */

static int findAssetIndex(int id)
{
    int i;

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].assetID == id)
        {
            return i;
        }
    }
    return -1;
}

static void printAsset(const Asset *a)
{
    printf("Asset ID       : %d\n", a->assetID);
    printf("Asset Name     : %s\n", a->assetName);
    printf("Asset Type     : %s\n", a->assetType);
    printf("Purchase Value : N$ %.2f\n", a->purchaseValue);
    printf("Department     : %s\n", a->department);
    printf("Condition      : %s\n", a->condition);
}

/* ---------- Main features ---------- */

void addAsset(void)
{
    Asset a;
    int id;

    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full!\n");
        return;
    }

    for (;;)
    {
        id = readInt("\nEnter Asset ID: ");

        if (id <= 0)
        {
            printf("ID must be a positive number.\n");
        }
        else if (findAssetIndex(id) >= 0)
        {
            printf("That ID already exists!\n");
        }
        else
        {
            break;
        }
    }
    a.assetID = id;

    readLine("Enter Asset Name: ", a.assetName, sizeof(a.assetName));
    readLine("Enter Asset Type: ", a.assetType, sizeof(a.assetType));
    a.purchaseValue = readNonNegativeDouble("Enter Purchase Value: ");
    readLine("Enter Department: ", a.department, sizeof(a.department));
    readLine("Enter Condition: ", a.condition, sizeof(a.condition));

    assets[assetCount] = a;
    assetCount++;

    printf("\nAsset added successfully!\n");
}

void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\n========== ASSET REGISTER ==========\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printAsset(&assets[i]);
    }
}

void searchAsset(void)
{
    int id = readInt("\nEnter Asset ID to search: ");
    int index = findAssetIndex(id);

    if (index < 0)
    {
        printf("\nAsset not found.\n");
        return;
    }

    printf("\nAsset Found!\n");
    printAsset(&assets[index]);
}

/* ---------- Menu ---------- */

int main(void)
{
    int choice;

    do
    {
        printf("\n========== ASSET MANAGEMENT ==========");
        printf("\n1. Add asset");
        printf("\n2. Display assets");
        printf("\n3. Search asset");
        printf("\n0. Exit");

        choice = readInt("\nChoose an option: ");

        switch (choice)
        {
            case 1:
                addAsset();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                searchAsset();
                break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please choose 0 to 3.\n");
        }
    } while (choice != 0);

    return 0;
}
