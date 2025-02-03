#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User profile structure
typedef struct {
    char username[50];
    double *engagementScores; // Pointer to engagement scores for each category
    int numCategories;
} UserProfile;

// Engagement matrix structure
typedef struct {
    double **matrix; // 2D array of engagement scores
    int numUsers;
    int numCategories;
} EngagementMatrix;

// Device preference structure
typedef struct {
    char deviceType[50];
    char resolutionPreference[20];
    char playbackHistory[100];
    double bandwidthUsage;
} DevicePreference;

// Device matrix structure
typedef struct {
    DevicePreference ***deviceMatrix; // 3D array: userIndex x deviceIndex
    int numUsers;
    int *numDevicesPerUser;
} DeviceMatrix;

// Content metadata structure
typedef struct {
    char title[100];
    double rating;
    int runtime; // in minutes
    char encodingFormat[20];
} ContentMetadata;

// Content matrix structure
typedef struct {
    ContentMetadata **contentMatrix; // 2D array: categoryIndex x contentIndex
    int numCategories;
    int *numContentsPerCategory; // Number of contents per category
} ContentMatrix;

int main() {
    int numUsers = 2;
    int numCategories = 3; // Example categories: Action, Drama, Comedy

    // Initialize EngagementMatrix
    EngagementMatrix engagementMatrix;
    engagementMatrix.numUsers = numUsers;
    engagementMatrix.numCategories = numCategories;
    engagementMatrix.matrix = (double **)malloc(sizeof(double *) * numUsers);
    for (int i = 0; i < numUsers; i++) {
        engagementMatrix.matrix[i] = (double *)malloc(sizeof(double) * numCategories);
        for (int j = 0; j < numCategories; j++) {
            engagementMatrix.matrix[i][j] = 0.0; // Initialize scores to zero
        }
    }

    // Initialize UserProfiles
    UserProfile *users = (UserProfile *)malloc(sizeof(UserProfile) * numUsers);
    for (int i = 0; i < numUsers; i++) {
        sprintf(users[i].username, "User%d", i + 1);
        users[i].numCategories = numCategories;
        users[i].engagementScores = engagementMatrix.matrix[i]; // Link to engagement matrix row
    }

    // Simulate engagement updates
    users[0].engagementScores[0] += 2.5; // User1 watches Action
    users[0].engagementScores[1] += 1.0; // User1 watches Drama
    users[1].engagementScores[2] += 3.0; // User2 watches Comedy

    // Initialize DeviceMatrix
    DeviceMatrix deviceMatrix;
    deviceMatrix.numUsers = numUsers;
    deviceMatrix.numDevicesPerUser = (int *)malloc(sizeof(int) * numUsers);
    deviceMatrix.deviceMatrix = (DevicePreference ***)malloc(sizeof(DevicePreference **) * numUsers);

    for (int i = 0; i < numUsers; i++) {
        int numDevices = 2; // Assume each user has 2 devices
        deviceMatrix.numDevicesPerUser[i] = numDevices;
        deviceMatrix.deviceMatrix[i] = (DevicePreference **)malloc(sizeof(DevicePreference *) * numDevices);

        for (int j = 0; j < numDevices; j++) {
            deviceMatrix.deviceMatrix[i][j] = (DevicePreference *)malloc(sizeof(DevicePreference));
            // Initialize device preferences
            if (j == 0) {
                strcpy(deviceMatrix.deviceMatrix[i][j]->deviceType, "Smartphone");
                strcpy(deviceMatrix.deviceMatrix[i][j]->resolutionPreference, "720p");
                strcpy(deviceMatrix.deviceMatrix[i][j]->playbackHistory, "Watched on the go");
                deviceMatrix.deviceMatrix[i][j]->bandwidthUsage = 1.5;
            } else {
                strcpy(deviceMatrix.deviceMatrix[i][j]->deviceType, "Smart TV");
                strcpy(deviceMatrix.deviceMatrix[i][j]->resolutionPreference, "1080p");
                strcpy(deviceMatrix.deviceMatrix[i][j]->playbackHistory, "Watched at home");
                deviceMatrix.deviceMatrix[i][j]->bandwidthUsage = 5.0;
            }
        }
    }

    // Initialize ContentMatrix
    ContentMatrix contentMatrix;
    contentMatrix.numCategories = numCategories;
    contentMatrix.numContentsPerCategory = (int *)malloc(sizeof(int) * numCategories);
    contentMatrix.contentMatrix = (ContentMetadata **)malloc(sizeof(ContentMetadata *) * numCategories);

    for (int i = 0; i < numCategories; i++) {
        int numContents = 2; // Assume each category has 2 contents
        contentMatrix.numContentsPerCategory[i] = numContents;
        contentMatrix.contentMatrix[i] = (ContentMetadata *)malloc(sizeof(ContentMetadata) * numContents);

        for (int j = 0; j < numContents; j++) {
            ContentMetadata *content = &contentMatrix.contentMatrix[i][j];
            sprintf(content->title, "Content%d_%d", i + 1, j + 1);
            content->rating = 4.5 - 0.5 * j;
            content->runtime = 90 + 10 * j;
            strcpy(content->encodingFormat, "H.264");
        }
    }

    // Display user engagement and device preferences
    for (int i = 0; i < numUsers; i++) {
        printf("\nUser: %s\n", users[i].username);
        printf("Engagement Scores:\n");
        for (int j = 0; j < numCategories; j++) {
            printf("Category %d: %f\n", j + 1, users[i].engagementScores[j]);
        }

        printf("Device Preferences:\n");
        for (int j = 0; j < deviceMatrix.numDevicesPerUser[i]; j++) {
            DevicePreference *devicePref = deviceMatrix.deviceMatrix[i][j];
            printf("\nDevice %d: %s\n", j + 1, devicePref->deviceType);
            printf("Resolution: %s\n", devicePref->resolutionPreference);
            printf("Playback History: %s\n", devicePref->playbackHistory);
            printf("Bandwidth Usage: %f\n", devicePref->bandwidthUsage);
        }
    }

    // Free allocated memory
    for (int i = 0; i < numUsers; i++) {
        free(users[i].engagementScores);
    }
    free(users);

    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < deviceMatrix.numDevicesPerUser[i]; j++) {
            free(deviceMatrix.deviceMatrix[i][j]);
        }
        free(deviceMatrix.deviceMatrix[i]);
    }
    free(deviceMatrix.deviceMatrix);
    free(deviceMatrix.numDevicesPerUser);

    for (int i = 0; i < numCategories; i++) {
        free(contentMatrix.contentMatrix[i]);
    }
    free(contentMatrix.contentMatrix);
    free(contentMatrix.numContentsPerCategory);

    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix.matrix[i]);
    }
    free(engagementMatrix.matrix);

    return 0;
}