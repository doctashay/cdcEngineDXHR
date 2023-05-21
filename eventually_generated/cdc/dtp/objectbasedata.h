#pragma once
#include <cstdint>

namespace cdc {

class AnimGraphRequest;
class ObjectBlobAnim;

}

namespace dtp {

struct Model;

struct ObjectBaseData {
	uint32_t dword0;
	uint32_t dword4;
	uint32_t dword8;
	uint32_t dwordC;
	float float10_lod1_distance_maybe;
	float float14_lod2_distance_maybe;
	uint8_t byte18_lod1_rmi_selector_maybe;
	uint8_t byte19_lod2_rmi_selector_maybe;
	uint8_t f1A[6];
	float float20;
	uint16_t word24;
	uint8_t byte26;
	uint8_t f27;
	float fl28;
	uint8_t f2C[4];
	uint16_t word30;
	uint8_t f32[6];
	uint16_t word38;
	uint8_t f3A[2];
	uint32_t dword3C;
	uint16_t word40;
	uint16_t word42;
	uint32_t dword44;
	uint32_t dword48;
	cdc::AnimGraphRequest **pAnimGraphReq4C;
	uint32_t numAnimGraphs54;
	struct { cdc::AnimGraphRequest *req; uint32_t unk4; } *animgraphs54;
	uint32_t dword58;
	uint32_t dword5C;
	uint32_t dword60;
	int field_64_IK;
	uint8_t gap68[4];
	int field_6C;
	uint8_t gap70[8];
	int field_78_cloth;
	int field_7C_softBody;
	uint32_t dword80;
	uint32_t hasSoundMaybe;
	uint32_t dword88;
	uint32_t dword8C;
	uint32_t dword90;
	uint32_t dword94_softAccessory;
	uint32_t dword98;
	uint32_t dword9C;
	uint32_t dwordA0;
	uint32_t dwordA4;
	uint32_t dwordA8;
	uint32_t dwordAC;
	uint32_t dwordB0;
	uint32_t dwordB4;
	uint32_t dwordB8;
	void *TuneDataPtr; // BC, override data in object by this
	uint32_t dwordC0;
	cdc::ObjectBlobAnim **animationsC4;
	uint32_t dwordC8;
	uint32_t dwordCC;
	uint32_t dwordD0;
	uint32_t dwordD4;
	uint32_t dwordD8;
	uint32_t dwordDC;
	uint32_t dwordE0;
	uint32_t dwordE4;
	uint32_t dwordE8;
	uint32_t dwordEC;
	uint32_t dwordF0;
	uint32_t dwordF4;
	uint32_t dwordF8;
	uint16_t numModels; // FC
	uint8_t fFE[2];
	dtp::Model **models;
	uint32_t dword104;
	uint32_t dword108;
	uint32_t dword10C;
	uint32_t dword110;
	uint32_t dword114;
	uint16_t baseObject_objectListIndex;
	uint16_t dword11A;
	uint32_t dword11C;
	uint32_t dword120;
	uint32_t dword124;
	uint32_t dword128;
	uint32_t hasDeferredLightMaybe;
};

}
