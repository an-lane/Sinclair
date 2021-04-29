//Ashley Nixon
//07/02/2019
//UberDriver.h - implementation of the UberDriver class

#ifndef UBERDRIVER_H
#define UBERDRIVER_H

#include <string>
using std::string;

class UberDriver {
	public:
		//default constrctuor
		UberDriver() {}

		//constructor with initialization
		UberDriver(int _ageOfDriver, int _yearsOfDrivingExperiance, string _isVehicleEnsuredToDriver, 
				string _isBackgroundCheckClear, string _isDriverRecordClear, string _driverHasSmartPhone)
			: ageOfDriver(_ageOfDriver),
				yearsOfDrivingExperiance(_yearsOfDrivingExperiance),
				isVehicleEnsuredToDriver(_isVehicleEnsuredToDriver),
				isBackgroundCheckClear(_isBackgroundCheckClear),
				isDriverRecordClear(_isDriverRecordClear),
				driverHasSmartPhone(_driverHasSmartPhone) {}

		//getters for private members
		int Get_ageOfDriver() const { return ageOfDriver; }
		int Get_yearsOfDrivingExperiance() const { return yearsOfDrivingExperiance;  }
		string Get_isVehicleEnsuredToDriver() const { return isVehicleEnsuredToDriver; }
		string Get_isBackgroundCheckClear() const { return isBackgroundCheckClear; }
		string Get_isDriverRecordClear() const { return isDriverRecordClear; }
		string Get_driverHasSmartPhone() const { return driverHasSmartPhone; }

		//Setters for private members
		void Set_ageOfDriver(int val) { ageOfDriver = val; }
		void Set_yearsOfDrivingExperiance(int val) { yearsOfDrivingExperiance = val; }
		void Set_isVehicleEnsuredToDriver(string val) { isVehicleEnsuredToDriver = val; }
		void Set_isBackgroundCheckClear(string val) { isBackgroundCheckClear = val; }
		void Set_isDriverRecordClear(string val) { isDriverRecordClear = val; }
		void Set_diverHasSmartPhone(string val) { driverHasSmartPhone = val; }

	private:
		int ageOfDriver;
		int yearsOfDrivingExperiance;
		string isVehicleEnsuredToDriver;
		string isBackgroundCheckClear;
		string isDriverRecordClear;
		string driverHasSmartPhone;
};

#endif //UBERDRIVER_H
