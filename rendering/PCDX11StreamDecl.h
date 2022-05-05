#pragma once
#include <cstdint>
#include <d3d11.h>
#include "PCDX11InternalResource.h"
// #include "CommonStreamDecl.h"
#include "CommonShader.h"

namespace cdc {

class PCDX11RenderDevice;

class PCDX11StreamDecl :
	public PCDX11InternalResource
	// public CommonStreamDecl
{
public:
	PCDX11StreamDecl(
		PCDX11RenderDevice *renderDevice,
		D3D11_INPUT_ELEMENT_DESC *elementDesc,
		uint32_t numElements,
		ShaderSub *shaderSub)
	:
		PCDX11InternalResource(),
		renderDevice(renderDevice),
		elementDesc(elementDesc),
		numElements(numElements),
		inputLayout(nullptr),
		shaderSub(shaderSub)
	{
		// InternalResource::...
	}

	PCDX11RenderDevice *renderDevice; // 10
	D3D11_INPUT_ELEMENT_DESC *elementDesc; // 1C
	uint32_t numElements; // 20
	ID3D11InputLayout *inputLayout; // 24
	ShaderSub *shaderSub; // 2C

	void apply();

	void internalResource04() override;
	void internalResource08() override;
};

}