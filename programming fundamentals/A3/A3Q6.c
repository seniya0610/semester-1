#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Weather forecast structure
typedef struct {
	float temperature;
	float rainfall;
	float windPatterns;
} WeatherForecast;

// Crop structure
typedef struct {
	char cropType[50];
	int growthStage;
	float expectedYield;
	WeatherForecast *weatherForecast; // Pointer to WeatherForecast
} Crop;

// Equipment structure
typedef struct {
	char equipmentType[50];
	char operationalStatus[20];
	float fuelLevel;
	char activitySchedule[100];
} Equipment;

// Sensor structure
typedef struct {
	float soilNutrients;
	float pHLevel;
	int pestActivity;
} Sensor;

// Field structure
typedef struct {
	float latitude;
	float longitude;
	float soilHealthMetrics;
	float moistureLevel;
	Crop *crops;          // Pointer to array of Crop structures
	int numCrops;
	Equipment *equipment; // Pointer to array of Equipment structures
	int numEquipment;
	Sensor *sensors;      // Pointer to array of Sensor structures
	int numSensors;
} Field;

// Regional hub structure
typedef struct {
	Field *fields;        // Pointer to array of Field structures
	int numFields;
	float yieldPrediction;
	char resourceDistribution[100];
	char emergencyResponsePlan[100];
} RegionalHub;

// Central analytics server structure
typedef struct {
	RegionalHub *regionalHubs;
	int numRegionalHubs;
} CentralAnalyticsServer;

int main() {
	// Create a central analytics server
	CentralAnalyticsServer centralServer;
	centralServer.numRegionalHubs = 1;
	centralServer.regionalHubs = (RegionalHub *)malloc(sizeof(RegionalHub) * centralServer.numRegionalHubs);

	// Create a regional hub
	RegionalHub *hub = &centralServer.regionalHubs[0];
	hub->numFields = 1;
	hub->fields = (Field *)malloc(sizeof(Field) * hub->numFields);
	hub->yieldPrediction = 10000.0f;
	strcpy(hub->resourceDistribution, "Equally distributed");
	strcpy(hub->emergencyResponsePlan, "Standard emergency plan");

	// Create a field
	Field *field = &hub->fields[0];
	field->latitude = 37.7749f;
	field->longitude = -122.4194f;
	field->soilHealthMetrics = 75.0f;
	field->moistureLevel = 30.0f;

	// Initialize crops
	field->numCrops = 2;
	field->crops = (Crop *)malloc(sizeof(Crop) * field->numCrops);

	// First crop
	Crop *crop1 = &field->crops[0];
	strcpy(crop1->cropType, "Corn");
	crop1->growthStage = 3;
	crop1->expectedYield = 500.0f;
	crop1->weatherForecast = (WeatherForecast *)malloc(sizeof(WeatherForecast));
	crop1->weatherForecast->temperature = 25.0f;
	crop1->weatherForecast->rainfall = 5.0f;
	crop1->weatherForecast->windPatterns = 2.0f;

	// Second crop
	Crop *crop2 = &field->crops[1];
	strcpy(crop2->cropType, "Wheat");
	crop2->growthStage = 2;
	crop2->expectedYield = 300.0f;
	crop2->weatherForecast = (WeatherForecast *)malloc(sizeof(WeatherForecast));
	crop2->weatherForecast->temperature = 22.0f;
	crop2->weatherForecast->rainfall = 3.0f;
	crop2->weatherForecast->windPatterns = 1.5f;

	// Initialize equipment
	field->numEquipment = 2;
	field->equipment = (Equipment *)malloc(sizeof(Equipment) * field->numEquipment);

	// First equipment
	Equipment *eq1 = &field->equipment[0];
	strcpy(eq1->equipmentType, "Autonomous Tractor");
	strcpy(eq1->operationalStatus, "Active");
	eq1->fuelLevel = 75.0f;
	strcpy(eq1->activitySchedule, "Plowing at 9 AM");

	// Second equipment
	Equipment *eq2 = &field->equipment[1];
	strcpy(eq2->equipmentType, "Irrigation System");
	strcpy(eq2->operationalStatus, "Inactive");
	eq2->fuelLevel = 0.0f; // Not applicable
	strcpy(eq2->activitySchedule, "Scheduled for 6 AM");

	// Initialize sensors
	field->numSensors = 2;
	field->sensors = (Sensor *)malloc(sizeof(Sensor) * field->numSensors);

	// First sensor
	Sensor *sensor1 = &field->sensors[0];
	sensor1->soilNutrients = 50.0f;
	sensor1->pHLevel = 6.5f;
	sensor1->pestActivity = 0;

	// Second sensor
	Sensor *sensor2 = &field->sensors[1];
	sensor2->soilNutrients = 55.0f;
	sensor2->pHLevel = 6.8f;
	sensor2->pestActivity = 1;

	// Display field data
	printf("Field at (%f, %f)\n", field->latitude, field->longitude);
	printf("Soil Health Metrics: %f\n", field->soilHealthMetrics);
	printf("Moisture Level: %f\n", field->moistureLevel);

	// Display crop data
	for (int i = 0; i < field->numCrops; i++) {
		Crop *crop = &field->crops[i];
		printf("\nCrop %d: %s\n", i + 1, crop->cropType);
		printf("Growth Stage: %d\n", crop->growthStage);
		printf("Expected Yield: %f\n", crop->expectedYield);
		printf("Weather Forecast - Temp: %f, Rainfall: %f, Wind: %f\n",
		       crop->weatherForecast->temperature,
		       crop->weatherForecast->rainfall,
		       crop->weatherForecast->windPatterns);
	}

	// Free allocated memory
	for (int i = 0; i < field->numCrops; i++) {
		free(field->crops[i].weatherForecast);
	}
	free(field->crops);
	free(field->equipment);
	free(field->sensors);
	free(hub->fields);
	free(centralServer.regionalHubs);

	return 0;
}