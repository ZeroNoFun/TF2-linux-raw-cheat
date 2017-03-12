
class Vector;
class Color;
class VPANEL;
class ClientClass;
typedef float matrix3x4[3][4];

class IVEngineClient
{
public:
	virtual void _pad_0() = 0;
	virtual void _pad_1() = 0;
	virtual void _pad_2() = 0;
	virtual void _pad_3() = 0;
	virtual void _pad_4() = 0;
	virtual void GetScreenSize(int& iWidth, int& iHeight);
	virtual void _pad_6() = 0;
	virtual void _pad_7() = 0;
	virtual void _pad_8() = 0;
	virtual void _pad_9() = 0;
	virtual void _pad_10() = 0;
	virtual void _pad_11() = 0;
	virtual int GetLocalPlayer() = 0;
	virtual void _pad_13() = 0;
	virtual void _pad_14() = 0;
	virtual void _pad_15() = 0;
	virtual void _pad_16() = 0;
	virtual void _pad_17() = 0;
	virtual void _pad_18() = 0;
	virtual void GetViewAngles( Vector& ang ) = 0;
	virtual void SetViewAngles( Vector& ang ) = 0;
	virtual int GetMaxClients() = 0;
	virtual void _pad_22() = 0;
	virtual void _pad_23() = 0;
	virtual void _pad_24() = 0;
	virtual void _pad_25() = 0;
	virtual void _pad_26() = 0;
	virtual void _pad_27() = 0;
	virtual void _pad_28() = 0;
	virtual void _pad_29() = 0;
	virtual void _pad_30() = 0;
	virtual void _pad_31() = 0;
	virtual void _pad_32() = 0;
	virtual void _pad_33() = 0;
	virtual void _pad_34() = 0;
	virtual void _pad_35() = 0;
	virtual const matrix3x4& WorldToScreenMatrix() = 0;
};

class ISurface
{
public:
	virtual void _pad_0() = 0;
	virtual void _pad_1() = 0;
	virtual void _pad_2() = 0;
	virtual void _pad_3() = 0;
	virtual void _pad_4() = 0;
	virtual void _pad_5() = 0;
	virtual void _pad_6() = 0;
	virtual void _pad_7() = 0;
	virtual void _pad_8() = 0;
	virtual void _pad_9() = 0;
	virtual void DrawSetColor(int r, int g, int b, int a) = 0;
	virtual void DrawSetColor(Color clr) = 0;
	virtual void DrawFilledRect(int x, int y, int w, int h) = 0;
	virtual void _pad_13() = 0;
	virtual void DrawOutlinedRect(int x, int y, int w, int h) = 0;
};

class IVPanel
{
public:
	virtual void _pad_0() = 0;
	virtual void _pad_1() = 0;
	virtual void _pad_2() = 0;
	virtual void _pad_3() = 0;
	virtual void _pad_4() = 0;
	virtual void _pad_5() = 0;
	virtual void _pad_6() = 0;
	virtual void _pad_7() = 0;
	virtual void _pad_8() = 0;
	virtual void _pad_9() = 0;
	virtual void _pad_10() = 0;
	virtual void _pad_11() = 0;
	virtual void _pad_12() = 0;
	virtual void _pad_13() = 0;
	virtual void _pad_14() = 0;
	virtual void _pad_15() = 0;
	virtual void _pad_16() = 0;
	virtual void _pad_17() = 0;
	virtual void _pad_18() = 0;
	virtual void _pad_19() = 0;
	virtual void _pad_20() = 0;
	virtual void _pad_21() = 0;
	virtual void _pad_22() = 0;
	virtual void _pad_23() = 0;
	virtual void _pad_24() = 0;
	virtual void _pad_25() = 0;
	virtual void _pad_26() = 0;
	virtual void _pad_27() = 0;
	virtual void _pad_28() = 0;
	virtual void _pad_29() = 0;
	virtual void _pad_30() = 0;
	virtual void _pad_31() = 0;
	virtual void _pad_32() = 0;
	virtual void _pad_33() = 0;
	virtual void _pad_34() = 0;
	virtual void _pad_35() = 0;
	virtual void _pad_36() = 0;
	virtual const char *GetName(unsigned int vguiPanel) = 0;
};

class IBaseClientDLL
{
public:
	virtual void _pad_0() = 0;
	virtual void _pad_1() = 0;
	virtual void _pad_2() = 0;
	virtual void _pad_3() = 0;
	virtual void _pad_4() = 0;
	virtual void _pad_5() = 0;
	virtual void _pad_6() = 0;
	virtual void _pad_7() = 0;
	virtual ClientClass *GetAllClasses() = 0;
};

class IEntityList
{
public:
	virtual void _pad_0() = 0;
	virtual void _pad_1() = 0;
	virtual void _pad_2() = 0;
	virtual void *GetClientEntity(int index) = 0;
};

class IClientEntity
{
public:
	virtual void _pad_0() = 0;
	virtual void _pad_1() = 0;
	virtual void _pad_2() = 0;
	virtual void _pad_3() = 0;
	virtual void _pad_4() = 0;
	virtual void _pad_5() = 0;
	virtual void _pad_6() = 0;
	virtual void _pad_7() = 0;
	virtual void _pad_8() = 0;
	virtual void _pad_9() = 0;
	virtual void _pad_10() = 0;
	virtual Vector& GetAbsOrigin() = 0;
};

