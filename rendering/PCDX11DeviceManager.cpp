#include <windows.h>
#include <d3d11_1.h>
#include "PCDX11DeviceManager.h"

namespace cdc {

PCDX11DeviceManager::PCDX11DeviceManager(HMODULE d3d11, HMODULE dxgi) :
	d3d11(d3d11),
	dxgi(dxgi)
{

}

PCDX11DeviceManager::PCDX11DeviceManager(
	HMODULE d3d11,
	HMODULE dxgi,
	ID3D11Device *device,
	ID3D11DeviceContext *deviceContext)
:
	d3d11(d3d11),
	dxgi(dxgi),
	device(device),
	deviceContext(deviceContext)
{
	auto createDXGIFactory = (decltype(&CreateDXGIFactory))(GetProcAddress(d3d11, "CreateDXGIFactory"));
	createDXGIFactory(__uuidof(IDXGIFactory), (void**)&dxgiFactory);
}

void PCDX11DeviceManager::method_00() {
	// TODO
}

DisplayConfig *PCDX11DeviceManager::getDisplayConfig() {
	return &config1;
}

void PCDX11DeviceManager::setBrightness(float brightness) {
	config1.brightness = brightness;
}

void PCDX11DeviceManager::method_0C() {
	// TODO
}

void PCDX11DeviceManager::method_10() {
	// TODO
}

void PCDX11DeviceManager::method_14() {
	// TODO
}

void PCDX11DeviceManager::method_18() {
	// TODO
}

void PCDX11DeviceManager::method_1C() {
	// TODO
}

void PCDX11DeviceManager::method_20() {
	// TODO
}

void PCDX11DeviceManager::method_24() {
	// TODO
}

PCDX11DeviceManager *deviceManager = nullptr;

PCDX11DeviceManager *createPCDX11DeviceManager() {
	HMODULE d3d11 = LoadLibraryA("d3d11.dll");
	if (!d3d11)
		return 0;

	HMODULE dxgi = LoadLibraryA("dxgi.dll");
	if (!dxgi) {
		FreeLibrary(d3d11);
		return 0;
	}

	auto createDevice = (decltype(&D3D11CreateDevice))(GetProcAddress(d3d11, "D3D11CreateDevice"));

	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
	D3D_FEATURE_LEVEL chosenFeatureLevel;
	
	ID3D11Device* baseDevice;
	ID3D11DeviceContext* baseDeviceContext;

	HRESULT r = D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		featureLevels,
		ARRAYSIZE(featureLevels),
		D3D11_SDK_VERSION,
		&baseDevice,
		&chosenFeatureLevel,
		&baseDeviceContext);

	if (r < 0) {
		FreeLibrary(dxgi);
		FreeLibrary(d3d11);
	}

	// ID3D11Device_Release(baseDevice);
	// ID3D11DeviceContext_Release(baseDeviceContext);

	deviceManager = new PCDX11DeviceManager(dxgi, d3d11, baseDevice, baseDeviceContext);
	return deviceManager;
}

}
