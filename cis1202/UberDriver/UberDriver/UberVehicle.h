//Ashley Nixon
//07/02/2019
//UberVehicle.h - implementation of the UberVehicle class

#ifndef UBERVEHICLE_H
#define UBERVEHICLE_H

#include <string>
using std::string;

class UberVehicle {
	public:
		//default constructor
		UberVehicle() {}

		//constrctor with initialization
		UberVehicle(int _vehicleNumberOfDoors, int _vehicleYear, string _vehicleMake,
					string _vehicleModel, string _inStateVehiclePlates, string _isVehicleMarketTaxiOrSalvage,
					string _hasVehiclePassedInspection, string _isVehicleRegistered)
			: vehicleNumberOfDoors(_vehicleNumberOfDoors),
				vehicleYear(_vehicleYear),
				vehicleMake(_vehicleMake),
				vehicleModel(_vehicleModel),
				inStateVehiclePlates(_inStateVehiclePlates),
				isVehicleMarketTaxiOrSalvage(_isVehicleMarketTaxiOrSalvage),
				hasVehiclePassedInspection(_hasVehiclePassedInspection),
				isVehicleRegistered(_isVehicleRegistered){}

		//getters for private members
		int Get_vehicleNumberOfDoors() const { return vehicleNumberOfDoors; }
		int Get_vehicleYear() const { return vehicleYear; }
		string Get_vehicleMake() const { return vehicleMake; }
		string Get_vehicleModel() const { return vehicleModel; }
		string Get_inStateVehiclePlates() const { return inStateVehiclePlates; }
		string Get_isVehicleMarketTaxiOrSalvage() const { return isVehicleMarketTaxiOrSalvage; }
		string Get_hasVehiclePassedInspection() const { return hasVehiclePassedInspection; }
		string Get_isVehicleRegistered() const { return isVehicleRegistered; }

		//setters for private members
		void Set_vehicleNumberOfDoors(int val) { vehicleNumberOfDoors = val; }
		void Set_vehicleYear(int val) { vehicleYear = val; }
		void Set_vehicleMake(string val) { vehicleMake = val; }
		void Set_vehicleModel(string val) { vehicleModel = val; }
		void Set_inStateVehiclePlates(string val) { inStateVehiclePlates = val; }
		void Set_isVehicleMarketTaxiOrSalvage(string val) { isVehicleMarketTaxiOrSalvage = val; }
		void Set_hasVehiclePassedInspection(string val) { hasVehiclePassedInspection = val; }
		void Set_isVehicleRegistered(string val) { isVehicleRegistered = val; }

	private:
		int vehicleNumberOfDoors;
		int vehicleYear;
		string vehicleMake;
		string vehicleModel;
		string inStateVehiclePlates;
		string isVehicleMarketTaxiOrSalvage;
		string hasVehiclePassedInspection;
		string isVehicleRegistered;
};

#endif // UBERVEHICLE_H