/* router.c generated by valac 0.16.1, the Vala compiler
 * generated from router.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Simon Busch <morphis@gravedo.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <fsobasics.h>
#include <freesmartphone.h>
#include <stdlib.h>
#include <string.h>


#define FSO_AUDIO_TYPE_IROUTER (fso_audio_irouter_get_type ())
#define FSO_AUDIO_IROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_IROUTER, FsoAudioIRouter))
#define FSO_AUDIO_IS_IROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_IROUTER))
#define FSO_AUDIO_IROUTER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_AUDIO_TYPE_IROUTER, FsoAudioIRouterIface))

typedef struct _FsoAudioIRouter FsoAudioIRouter;
typedef struct _FsoAudioIRouterIface FsoAudioIRouterIface;

#define FSO_AUDIO_TYPE_ABSTRACT_ROUTER (fso_audio_abstract_router_get_type ())
#define FSO_AUDIO_ABSTRACT_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_ABSTRACT_ROUTER, FsoAudioAbstractRouter))
#define FSO_AUDIO_ABSTRACT_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_ABSTRACT_ROUTER, FsoAudioAbstractRouterClass))
#define FSO_AUDIO_IS_ABSTRACT_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_ABSTRACT_ROUTER))
#define FSO_AUDIO_IS_ABSTRACT_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_ABSTRACT_ROUTER))
#define FSO_AUDIO_ABSTRACT_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_ABSTRACT_ROUTER, FsoAudioAbstractRouterClass))

typedef struct _FsoAudioAbstractRouter FsoAudioAbstractRouter;
typedef struct _FsoAudioAbstractRouterClass FsoAudioAbstractRouterClass;
typedef struct _FsoAudioAbstractRouterPrivate FsoAudioAbstractRouterPrivate;

#define FSO_AUDIO_TYPE_NULL_ROUTER (fso_audio_null_router_get_type ())
#define FSO_AUDIO_NULL_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_NULL_ROUTER, FsoAudioNullRouter))
#define FSO_AUDIO_NULL_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_NULL_ROUTER, FsoAudioNullRouterClass))
#define FSO_AUDIO_IS_NULL_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_NULL_ROUTER))
#define FSO_AUDIO_IS_NULL_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_NULL_ROUTER))
#define FSO_AUDIO_NULL_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_NULL_ROUTER, FsoAudioNullRouterClass))

typedef struct _FsoAudioNullRouter FsoAudioNullRouter;
typedef struct _FsoAudioNullRouterClass FsoAudioNullRouterClass;
typedef struct _FsoAudioNullRouterPrivate FsoAudioNullRouterPrivate;

struct _FsoAudioIRouterIface {
	GTypeInterface parent_iface;
	void (*set_mode) (FsoAudioIRouter* self, FreeSmartphoneAudioMode mode, gboolean force);
	void (*set_device) (FsoAudioIRouter* self, FreeSmartphoneAudioDevice device, gboolean expose);
	void (*set_volume) (FsoAudioIRouter* self, FreeSmartphoneAudioControl control, guint volume);
	FreeSmartphoneAudioDevice* (*get_available_devices) (FsoAudioIRouter* self, FreeSmartphoneAudioMode mode, int* result_length1);
};

struct _FsoAudioAbstractRouter {
	FsoFrameworkAbstractObject parent_instance;
	FsoAudioAbstractRouterPrivate * priv;
	FreeSmartphoneAudioMode current_mode;
	FreeSmartphoneAudioDevice current_device;
	FreeSmartphoneAudioDevice* call_supported_devices;
	gint call_supported_devices_length1;
	FreeSmartphoneAudioDevice* normal_supported_devices;
	gint normal_supported_devices_length1;
};

struct _FsoAudioAbstractRouterClass {
	FsoFrameworkAbstractObjectClass parent_class;
	void (*set_mode) (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, gboolean force);
	void (*set_device) (FsoAudioAbstractRouter* self, FreeSmartphoneAudioDevice device, gboolean expose);
	void (*set_volume) (FsoAudioAbstractRouter* self, FreeSmartphoneAudioControl control, guint volume);
	FreeSmartphoneAudioDevice* (*get_available_devices) (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, int* result_length1);
};

struct _FsoAudioNullRouter {
	FsoAudioAbstractRouter parent_instance;
	FsoAudioNullRouterPrivate * priv;
};

struct _FsoAudioNullRouterClass {
	FsoAudioAbstractRouterClass parent_class;
};


static gpointer fso_audio_abstract_router_parent_class = NULL;
static FsoAudioIRouterIface* fso_audio_abstract_router_fso_audio_irouter_parent_iface = NULL;
static gpointer fso_audio_null_router_parent_class = NULL;

GType fso_audio_irouter_get_type (void) G_GNUC_CONST;
void fso_audio_irouter_set_mode (FsoAudioIRouter* self, FreeSmartphoneAudioMode mode, gboolean force);
void fso_audio_irouter_set_device (FsoAudioIRouter* self, FreeSmartphoneAudioDevice device, gboolean expose);
void fso_audio_irouter_set_volume (FsoAudioIRouter* self, FreeSmartphoneAudioControl control, guint volume);
FreeSmartphoneAudioDevice* fso_audio_irouter_get_available_devices (FsoAudioIRouter* self, FreeSmartphoneAudioMode mode, int* result_length1);
GType fso_audio_abstract_router_get_type (void) G_GNUC_CONST;
enum  {
	FSO_AUDIO_ABSTRACT_ROUTER_DUMMY_PROPERTY
};
void fso_audio_abstract_router_set_mode (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, gboolean force);
static void fso_audio_abstract_router_real_set_mode (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, gboolean force);
void fso_audio_abstract_router_set_device (FsoAudioAbstractRouter* self, FreeSmartphoneAudioDevice device, gboolean expose);
static void fso_audio_abstract_router_real_set_device (FsoAudioAbstractRouter* self, FreeSmartphoneAudioDevice device, gboolean expose);
void fso_audio_abstract_router_set_volume (FsoAudioAbstractRouter* self, FreeSmartphoneAudioControl control, guint volume);
static void fso_audio_abstract_router_real_set_volume (FsoAudioAbstractRouter* self, FreeSmartphoneAudioControl control, guint volume);
FreeSmartphoneAudioDevice* fso_audio_abstract_router_get_available_devices (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, int* result_length1);
static FreeSmartphoneAudioDevice* fso_audio_abstract_router_real_get_available_devices (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, int* result_length1);
static FreeSmartphoneAudioDevice* _vala_array_dup1 (FreeSmartphoneAudioDevice* self, int length);
static FreeSmartphoneAudioDevice* _vala_array_dup2 (FreeSmartphoneAudioDevice* self, int length);
FsoAudioAbstractRouter* fso_audio_abstract_router_construct (GType object_type);
static void fso_audio_abstract_router_finalize (GObject* obj);
GType fso_audio_null_router_get_type (void) G_GNUC_CONST;
enum  {
	FSO_AUDIO_NULL_ROUTER_DUMMY_PROPERTY
};
static FreeSmartphoneAudioDevice* fso_audio_null_router_real_get_available_devices (FsoAudioAbstractRouter* base, FreeSmartphoneAudioMode mode, int* result_length1);
static gchar* fso_audio_null_router_real_repr (FsoFrameworkAbstractObject* base);
FsoAudioNullRouter* fso_audio_null_router_new (void);
FsoAudioNullRouter* fso_audio_null_router_construct (GType object_type);


void fso_audio_irouter_set_mode (FsoAudioIRouter* self, FreeSmartphoneAudioMode mode, gboolean force) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_IROUTER_GET_INTERFACE (self)->set_mode (self, mode, force);
}


void fso_audio_irouter_set_device (FsoAudioIRouter* self, FreeSmartphoneAudioDevice device, gboolean expose) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_IROUTER_GET_INTERFACE (self)->set_device (self, device, expose);
}


void fso_audio_irouter_set_volume (FsoAudioIRouter* self, FreeSmartphoneAudioControl control, guint volume) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_IROUTER_GET_INTERFACE (self)->set_volume (self, control, volume);
}


FreeSmartphoneAudioDevice* fso_audio_irouter_get_available_devices (FsoAudioIRouter* self, FreeSmartphoneAudioMode mode, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_AUDIO_IROUTER_GET_INTERFACE (self)->get_available_devices (self, mode, result_length1);
}


static void fso_audio_irouter_base_init (FsoAudioIRouterIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType fso_audio_irouter_get_type (void) {
	static volatile gsize fso_audio_irouter_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_irouter_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioIRouterIface), (GBaseInitFunc) fso_audio_irouter_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_audio_irouter_type_id;
		fso_audio_irouter_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoAudioIRouter", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_audio_irouter_type_id, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT);
		g_once_init_leave (&fso_audio_irouter_type_id__volatile, fso_audio_irouter_type_id);
	}
	return fso_audio_irouter_type_id__volatile;
}


static void fso_audio_abstract_router_real_set_mode (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, gboolean force) {
	FreeSmartphoneAudioMode _tmp0_;
	_tmp0_ = mode;
	self->current_mode = _tmp0_;
}


void fso_audio_abstract_router_set_mode (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, gboolean force) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_ROUTER_GET_CLASS (self)->set_mode (self, mode, force);
}


static void fso_audio_abstract_router_real_set_device (FsoAudioAbstractRouter* self, FreeSmartphoneAudioDevice device, gboolean expose) {
	FreeSmartphoneAudioDevice _tmp0_;
	_tmp0_ = device;
	self->current_device = _tmp0_;
}


void fso_audio_abstract_router_set_device (FsoAudioAbstractRouter* self, FreeSmartphoneAudioDevice device, gboolean expose) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_ROUTER_GET_CLASS (self)->set_device (self, device, expose);
}


static void fso_audio_abstract_router_real_set_volume (FsoAudioAbstractRouter* self, FreeSmartphoneAudioControl control, guint volume) {
}


void fso_audio_abstract_router_set_volume (FsoAudioAbstractRouter* self, FreeSmartphoneAudioControl control, guint volume) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_ROUTER_GET_CLASS (self)->set_volume (self, control, volume);
}


static FreeSmartphoneAudioDevice* _vala_array_dup1 (FreeSmartphoneAudioDevice* self, int length) {
	return g_memdup (self, length * sizeof (FreeSmartphoneAudioDevice));
}


static FreeSmartphoneAudioDevice* _vala_array_dup2 (FreeSmartphoneAudioDevice* self, int length) {
	return g_memdup (self, length * sizeof (FreeSmartphoneAudioDevice));
}


static FreeSmartphoneAudioDevice* fso_audio_abstract_router_real_get_available_devices (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, int* result_length1) {
	FreeSmartphoneAudioDevice* result = NULL;
	FreeSmartphoneAudioDevice* _tmp0_ = NULL;
	FreeSmartphoneAudioDevice* _result_;
	gint _result__length1;
	gint __result__size_;
	FreeSmartphoneAudioMode _tmp1_;
	FreeSmartphoneAudioDevice* _tmp6_;
	gint _tmp6__length1;
	_tmp0_ = g_new0 (FreeSmartphoneAudioDevice, 0);
	_result_ = _tmp0_;
	_result__length1 = 0;
	__result__size_ = _result__length1;
	_tmp1_ = mode;
	switch (_tmp1_) {
		case FREE_SMARTPHONE_AUDIO_MODE_NORMAL:
		{
			FreeSmartphoneAudioDevice* _tmp2_;
			gint _tmp2__length1;
			FreeSmartphoneAudioDevice* _tmp3_;
			gint _tmp3__length1;
			_tmp2_ = self->normal_supported_devices;
			_tmp2__length1 = self->normal_supported_devices_length1;
			_tmp3_ = (_tmp2_ != NULL) ? _vala_array_dup1 (_tmp2_, _tmp2__length1) : ((gpointer) _tmp2_);
			_tmp3__length1 = _tmp2__length1;
			_result_ = (g_free (_result_), NULL);
			_result_ = _tmp3_;
			_result__length1 = _tmp3__length1;
			__result__size_ = _result__length1;
			break;
		}
		case FREE_SMARTPHONE_AUDIO_MODE_CALL:
		{
			FreeSmartphoneAudioDevice* _tmp4_;
			gint _tmp4__length1;
			FreeSmartphoneAudioDevice* _tmp5_;
			gint _tmp5__length1;
			_tmp4_ = self->call_supported_devices;
			_tmp4__length1 = self->call_supported_devices_length1;
			_tmp5_ = (_tmp4_ != NULL) ? _vala_array_dup2 (_tmp4_, _tmp4__length1) : ((gpointer) _tmp4_);
			_tmp5__length1 = _tmp4__length1;
			_result_ = (g_free (_result_), NULL);
			_result_ = _tmp5_;
			_result__length1 = _tmp5__length1;
			__result__size_ = _result__length1;
			break;
		}
		default:
		break;
	}
	_tmp6_ = _result_;
	_tmp6__length1 = _result__length1;
	if (result_length1) {
		*result_length1 = _tmp6__length1;
	}
	result = _tmp6_;
	return result;
}


FreeSmartphoneAudioDevice* fso_audio_abstract_router_get_available_devices (FsoAudioAbstractRouter* self, FreeSmartphoneAudioMode mode, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_AUDIO_ABSTRACT_ROUTER_GET_CLASS (self)->get_available_devices (self, mode, result_length1);
}


FsoAudioAbstractRouter* fso_audio_abstract_router_construct (GType object_type) {
	FsoAudioAbstractRouter * self = NULL;
	self = (FsoAudioAbstractRouter*) fso_framework_abstract_object_construct (object_type);
	return self;
}


static void fso_audio_abstract_router_class_init (FsoAudioAbstractRouterClass * klass) {
	fso_audio_abstract_router_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_ABSTRACT_ROUTER_CLASS (klass)->set_mode = fso_audio_abstract_router_real_set_mode;
	FSO_AUDIO_ABSTRACT_ROUTER_CLASS (klass)->set_device = fso_audio_abstract_router_real_set_device;
	FSO_AUDIO_ABSTRACT_ROUTER_CLASS (klass)->set_volume = fso_audio_abstract_router_real_set_volume;
	FSO_AUDIO_ABSTRACT_ROUTER_CLASS (klass)->get_available_devices = fso_audio_abstract_router_real_get_available_devices;
	G_OBJECT_CLASS (klass)->finalize = fso_audio_abstract_router_finalize;
}


static void fso_audio_abstract_router_fso_audio_irouter_interface_init (FsoAudioIRouterIface * iface) {
	fso_audio_abstract_router_fso_audio_irouter_parent_iface = g_type_interface_peek_parent (iface);
	iface->set_mode = (void (*)(FsoAudioIRouter*, FreeSmartphoneAudioMode, gboolean)) fso_audio_abstract_router_set_mode;
	iface->set_device = (void (*)(FsoAudioIRouter*, FreeSmartphoneAudioDevice, gboolean)) fso_audio_abstract_router_set_device;
	iface->set_volume = (void (*)(FsoAudioIRouter*, FreeSmartphoneAudioControl, guint)) fso_audio_abstract_router_set_volume;
	iface->get_available_devices = (FreeSmartphoneAudioDevice* (*)(FsoAudioIRouter*, FreeSmartphoneAudioMode, int*)) fso_audio_abstract_router_get_available_devices;
}


static void fso_audio_abstract_router_instance_init (FsoAudioAbstractRouter * self) {
}


static void fso_audio_abstract_router_finalize (GObject* obj) {
	FsoAudioAbstractRouter * self;
	self = FSO_AUDIO_ABSTRACT_ROUTER (obj);
	self->call_supported_devices = (g_free (self->call_supported_devices), NULL);
	self->normal_supported_devices = (g_free (self->normal_supported_devices), NULL);
	G_OBJECT_CLASS (fso_audio_abstract_router_parent_class)->finalize (obj);
}


GType fso_audio_abstract_router_get_type (void) {
	static volatile gsize fso_audio_abstract_router_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_abstract_router_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioAbstractRouterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_abstract_router_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioAbstractRouter), 0, (GInstanceInitFunc) fso_audio_abstract_router_instance_init, NULL };
		static const GInterfaceInfo fso_audio_irouter_info = { (GInterfaceInitFunc) fso_audio_abstract_router_fso_audio_irouter_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_audio_abstract_router_type_id;
		fso_audio_abstract_router_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoAudioAbstractRouter", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_type_add_interface_static (fso_audio_abstract_router_type_id, FSO_AUDIO_TYPE_IROUTER, &fso_audio_irouter_info);
		g_once_init_leave (&fso_audio_abstract_router_type_id__volatile, fso_audio_abstract_router_type_id);
	}
	return fso_audio_abstract_router_type_id__volatile;
}


static FreeSmartphoneAudioDevice* fso_audio_null_router_real_get_available_devices (FsoAudioAbstractRouter* base, FreeSmartphoneAudioMode mode, int* result_length1) {
	FsoAudioNullRouter * self;
	FreeSmartphoneAudioDevice* result = NULL;
	FreeSmartphoneAudioDevice* _tmp0_ = NULL;
	FreeSmartphoneAudioDevice* _tmp1_;
	gint _tmp1__length1;
	self = (FsoAudioNullRouter*) base;
	_tmp0_ = g_new0 (FreeSmartphoneAudioDevice, 0);
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 0;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


static gchar* fso_audio_null_router_real_repr (FsoFrameworkAbstractObject* base) {
	FsoAudioNullRouter * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoAudioNullRouter*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


FsoAudioNullRouter* fso_audio_null_router_construct (GType object_type) {
	FsoAudioNullRouter * self = NULL;
	self = (FsoAudioNullRouter*) fso_audio_abstract_router_construct (object_type);
	return self;
}


FsoAudioNullRouter* fso_audio_null_router_new (void) {
	return fso_audio_null_router_construct (FSO_AUDIO_TYPE_NULL_ROUTER);
}


static void fso_audio_null_router_class_init (FsoAudioNullRouterClass * klass) {
	fso_audio_null_router_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_ABSTRACT_ROUTER_CLASS (klass)->get_available_devices = fso_audio_null_router_real_get_available_devices;
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_audio_null_router_real_repr;
}


static void fso_audio_null_router_instance_init (FsoAudioNullRouter * self) {
}


GType fso_audio_null_router_get_type (void) {
	static volatile gsize fso_audio_null_router_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_null_router_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioNullRouterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_null_router_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioNullRouter), 0, (GInstanceInitFunc) fso_audio_null_router_instance_init, NULL };
		GType fso_audio_null_router_type_id;
		fso_audio_null_router_type_id = g_type_register_static (FSO_AUDIO_TYPE_ABSTRACT_ROUTER, "FsoAudioNullRouter", &g_define_type_info, 0);
		g_once_init_leave (&fso_audio_null_router_type_id__volatile, fso_audio_null_router_type_id);
	}
	return fso_audio_null_router_type_id__volatile;
}



