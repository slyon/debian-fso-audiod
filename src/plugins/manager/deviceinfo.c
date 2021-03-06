/* deviceinfo.c generated by valac 0.16.1, the Vala compiler
 * generated from deviceinfo.vala, do not modify */

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
#include <freesmartphone.h>
#include <gobject/gvaluecollector.h>


#define FSO_AUDIO_TYPE_DEVICE_INFO (fso_audio_device_info_get_type ())
#define FSO_AUDIO_DEVICE_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_DEVICE_INFO, FsoAudioDeviceInfo))
#define FSO_AUDIO_DEVICE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_DEVICE_INFO, FsoAudioDeviceInfoClass))
#define FSO_AUDIO_IS_DEVICE_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_DEVICE_INFO))
#define FSO_AUDIO_IS_DEVICE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_DEVICE_INFO))
#define FSO_AUDIO_DEVICE_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_DEVICE_INFO, FsoAudioDeviceInfoClass))

typedef struct _FsoAudioDeviceInfo FsoAudioDeviceInfo;
typedef struct _FsoAudioDeviceInfoClass FsoAudioDeviceInfoClass;
typedef struct _FsoAudioDeviceInfoPrivate FsoAudioDeviceInfoPrivate;

#define FSO_AUDIO_TYPE_CONTROL_INFO (fso_audio_control_info_get_type ())
#define FSO_AUDIO_CONTROL_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_CONTROL_INFO, FsoAudioControlInfo))
#define FSO_AUDIO_CONTROL_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_CONTROL_INFO, FsoAudioControlInfoClass))
#define FSO_AUDIO_IS_CONTROL_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_CONTROL_INFO))
#define FSO_AUDIO_IS_CONTROL_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_CONTROL_INFO))
#define FSO_AUDIO_CONTROL_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_CONTROL_INFO, FsoAudioControlInfoClass))

typedef struct _FsoAudioControlInfo FsoAudioControlInfo;
typedef struct _FsoAudioControlInfoClass FsoAudioControlInfoClass;
typedef struct _FsoAudioControlInfoPrivate FsoAudioControlInfoPrivate;
typedef struct _FsoAudioParamSpecDeviceInfo FsoAudioParamSpecDeviceInfo;

struct _FsoAudioDeviceInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FsoAudioDeviceInfoPrivate * priv;
	FreeSmartphoneAudioDevice type;
	FsoAudioControlInfo** call_controls;
	gint call_controls_length1;
	FsoAudioControlInfo** normal_controls;
	gint normal_controls_length1;
};

struct _FsoAudioDeviceInfoClass {
	GTypeClass parent_class;
	void (*finalize) (FsoAudioDeviceInfo *self);
};

struct _FsoAudioControlInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FsoAudioControlInfoPrivate * priv;
	FreeSmartphoneAudioControl type;
	gint volume;
	gboolean muted;
};

struct _FsoAudioControlInfoClass {
	GTypeClass parent_class;
	void (*finalize) (FsoAudioControlInfo *self);
};

struct _FsoAudioParamSpecDeviceInfo {
	GParamSpec parent_instance;
};


static gpointer fso_audio_device_info_parent_class = NULL;
static GType fso_audio_device_info_type_id = 0;

gpointer fso_audio_device_info_ref (gpointer instance);
void fso_audio_device_info_unref (gpointer instance);
GParamSpec* fso_audio_param_spec_device_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_audio_value_set_device_info (GValue* value, gpointer v_object);
void fso_audio_value_take_device_info (GValue* value, gpointer v_object);
gpointer fso_audio_value_get_device_info (const GValue* value);
GType fso_audio_device_info_get_type (void) G_GNUC_CONST;
GType fso_audio_device_info_register_type (GTypeModule * module);
gpointer fso_audio_control_info_ref (gpointer instance);
void fso_audio_control_info_unref (gpointer instance);
GParamSpec* fso_audio_param_spec_control_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_audio_value_set_control_info (GValue* value, gpointer v_object);
void fso_audio_value_take_control_info (GValue* value, gpointer v_object);
gpointer fso_audio_value_get_control_info (const GValue* value);
GType fso_audio_control_info_get_type (void) G_GNUC_CONST;
GType fso_audio_control_info_register_type (GTypeModule * module);
enum  {
	FSO_AUDIO_DEVICE_INFO_DUMMY_PROPERTY
};
FsoAudioDeviceInfo* fso_audio_device_info_new (FreeSmartphoneAudioDevice type);
FsoAudioDeviceInfo* fso_audio_device_info_construct (GType object_type, FreeSmartphoneAudioDevice type);
FsoAudioControlInfo* fso_audio_control_info_new (FreeSmartphoneAudioControl type, gint volume);
FsoAudioControlInfo* fso_audio_control_info_construct (GType object_type, FreeSmartphoneAudioControl type, gint volume);
static FsoAudioControlInfo** fso_audio_device_info_get_controls (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, int* result_length1);
static FsoAudioControlInfo** _vala_array_dup1 (FsoAudioControlInfo** self, int length);
void fso_audio_device_info_set_volume (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl, gint volume);
gint fso_audio_device_info_get_volume (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl);
void fso_audio_device_info_set_mute (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl, gboolean mute);
gboolean fso_audio_device_info_get_mute (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl);
static void fso_audio_device_info_finalize (FsoAudioDeviceInfo* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


FsoAudioDeviceInfo* fso_audio_device_info_construct (GType object_type, FreeSmartphoneAudioDevice type) {
	FsoAudioDeviceInfo* self = NULL;
	FreeSmartphoneAudioDevice _tmp0_;
	FsoAudioControlInfo* _tmp1_;
	FsoAudioControlInfo* _tmp2_;
	FsoAudioControlInfo** _tmp3_ = NULL;
	FsoAudioControlInfo* _tmp4_;
	FsoAudioControlInfo* _tmp5_;
	FsoAudioControlInfo** _tmp6_ = NULL;
	self = (FsoAudioDeviceInfo*) g_type_create_instance (object_type);
	_tmp0_ = type;
	self->type = _tmp0_;
	_tmp1_ = fso_audio_control_info_new (FREE_SMARTPHONE_AUDIO_CONTROL_SPEAKER, 80);
	_tmp2_ = fso_audio_control_info_new (FREE_SMARTPHONE_AUDIO_CONTROL_MICROPHONE, 80);
	_tmp3_ = g_new0 (FsoAudioControlInfo*, 2 + 1);
	_tmp3_[0] = _tmp1_;
	_tmp3_[1] = _tmp2_;
	self->normal_controls = (_vala_array_free (self->normal_controls, self->normal_controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
	self->normal_controls = _tmp3_;
	self->normal_controls_length1 = 2;
	_tmp4_ = fso_audio_control_info_new (FREE_SMARTPHONE_AUDIO_CONTROL_SPEAKER, 80);
	_tmp5_ = fso_audio_control_info_new (FREE_SMARTPHONE_AUDIO_CONTROL_MICROPHONE, 80);
	_tmp6_ = g_new0 (FsoAudioControlInfo*, 2 + 1);
	_tmp6_[0] = _tmp4_;
	_tmp6_[1] = _tmp5_;
	self->call_controls = (_vala_array_free (self->call_controls, self->call_controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
	self->call_controls = _tmp6_;
	self->call_controls_length1 = 2;
	return self;
}


FsoAudioDeviceInfo* fso_audio_device_info_new (FreeSmartphoneAudioDevice type) {
	return fso_audio_device_info_construct (FSO_AUDIO_TYPE_DEVICE_INFO, type);
}


static gpointer _fso_audio_control_info_ref0 (gpointer self) {
	return self ? fso_audio_control_info_ref (self) : NULL;
}


static FsoAudioControlInfo** _vala_array_dup1 (FsoAudioControlInfo** self, int length) {
	FsoAudioControlInfo** result;
	int i;
	result = g_new0 (FsoAudioControlInfo*, length + 1);
	for (i = 0; i < length; i++) {
		FsoAudioControlInfo* _tmp0_;
		_tmp0_ = _fso_audio_control_info_ref0 (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


static FsoAudioControlInfo** fso_audio_device_info_get_controls (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, int* result_length1) {
	FsoAudioControlInfo** result = NULL;
	FsoAudioControlInfo** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gint __tmp0__size_ = 0;
	FreeSmartphoneAudioMode _tmp1_;
	FsoAudioControlInfo** _tmp4_;
	gint _tmp4__length1;
	FsoAudioControlInfo** _tmp5_;
	gint _tmp5__length1;
	FsoAudioControlInfo** _tmp6_;
	gint _tmp6__length1;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = mode;
	if (_tmp1_ == FREE_SMARTPHONE_AUDIO_MODE_NORMAL) {
		FsoAudioControlInfo** _tmp2_;
		gint _tmp2__length1;
		_tmp2_ = self->normal_controls;
		_tmp2__length1 = self->normal_controls_length1;
		_tmp0_ = _tmp2_;
		_tmp0__length1 = _tmp2__length1;
		__tmp0__size_ = _tmp0__length1;
	} else {
		FsoAudioControlInfo** _tmp3_;
		gint _tmp3__length1;
		_tmp3_ = self->call_controls;
		_tmp3__length1 = self->call_controls_length1;
		_tmp0_ = _tmp3_;
		_tmp0__length1 = _tmp3__length1;
		__tmp0__size_ = _tmp0__length1;
	}
	_tmp4_ = _tmp0_;
	_tmp4__length1 = _tmp0__length1;
	_tmp5_ = (_tmp4_ != NULL) ? _vala_array_dup1 (_tmp4_, _tmp4__length1) : ((gpointer) _tmp4_);
	_tmp5__length1 = _tmp4__length1;
	_tmp6_ = _tmp5_;
	_tmp6__length1 = _tmp5__length1;
	if (result_length1) {
		*result_length1 = _tmp6__length1;
	}
	result = _tmp6_;
	return result;
}


void fso_audio_device_info_set_volume (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl, gint volume) {
	FreeSmartphoneAudioMode _tmp0_;
	gint _tmp1_ = 0;
	FsoAudioControlInfo** _tmp2_ = NULL;
	FsoAudioControlInfo** controls;
	gint controls_length1;
	gint _controls_size_;
	FreeSmartphoneAudioControl _tmp3_;
	FsoAudioControlInfo* _tmp4_;
	gint _tmp5_;
	g_return_if_fail (self != NULL);
	_tmp0_ = mode;
	_tmp2_ = fso_audio_device_info_get_controls (self, _tmp0_, &_tmp1_);
	controls = _tmp2_;
	controls_length1 = _tmp1_;
	_controls_size_ = controls_length1;
	_tmp3_ = ctrl;
	_tmp4_ = controls[_tmp3_];
	_tmp5_ = volume;
	_tmp4_->volume = _tmp5_;
	controls = (_vala_array_free (controls, controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
}


gint fso_audio_device_info_get_volume (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl) {
	gint result = 0;
	FreeSmartphoneAudioMode _tmp0_;
	gint _tmp1_ = 0;
	FsoAudioControlInfo** _tmp2_ = NULL;
	FsoAudioControlInfo** controls;
	gint controls_length1;
	gint _controls_size_;
	FreeSmartphoneAudioControl _tmp3_;
	FsoAudioControlInfo* _tmp4_;
	gint _tmp5_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = mode;
	_tmp2_ = fso_audio_device_info_get_controls (self, _tmp0_, &_tmp1_);
	controls = _tmp2_;
	controls_length1 = _tmp1_;
	_controls_size_ = controls_length1;
	_tmp3_ = ctrl;
	_tmp4_ = controls[_tmp3_];
	_tmp5_ = _tmp4_->volume;
	result = _tmp5_;
	controls = (_vala_array_free (controls, controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
	return result;
}


void fso_audio_device_info_set_mute (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl, gboolean mute) {
	FreeSmartphoneAudioMode _tmp0_;
	gint _tmp1_ = 0;
	FsoAudioControlInfo** _tmp2_ = NULL;
	FsoAudioControlInfo** controls;
	gint controls_length1;
	gint _controls_size_;
	FreeSmartphoneAudioControl _tmp3_;
	FsoAudioControlInfo* _tmp4_;
	gboolean _tmp5_;
	g_return_if_fail (self != NULL);
	_tmp0_ = mode;
	_tmp2_ = fso_audio_device_info_get_controls (self, _tmp0_, &_tmp1_);
	controls = _tmp2_;
	controls_length1 = _tmp1_;
	_controls_size_ = controls_length1;
	_tmp3_ = ctrl;
	_tmp4_ = controls[_tmp3_];
	_tmp5_ = mute;
	_tmp4_->muted = _tmp5_;
	controls = (_vala_array_free (controls, controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
}


gboolean fso_audio_device_info_get_mute (FsoAudioDeviceInfo* self, FreeSmartphoneAudioMode mode, FreeSmartphoneAudioControl ctrl) {
	gboolean result = FALSE;
	FreeSmartphoneAudioMode _tmp0_;
	gint _tmp1_ = 0;
	FsoAudioControlInfo** _tmp2_ = NULL;
	FsoAudioControlInfo** controls;
	gint controls_length1;
	gint _controls_size_;
	FreeSmartphoneAudioControl _tmp3_;
	FsoAudioControlInfo* _tmp4_;
	gboolean _tmp5_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = mode;
	_tmp2_ = fso_audio_device_info_get_controls (self, _tmp0_, &_tmp1_);
	controls = _tmp2_;
	controls_length1 = _tmp1_;
	_controls_size_ = controls_length1;
	_tmp3_ = ctrl;
	_tmp4_ = controls[_tmp3_];
	_tmp5_ = _tmp4_->muted;
	result = _tmp5_;
	controls = (_vala_array_free (controls, controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
	return result;
}


static void fso_audio_value_device_info_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void fso_audio_value_device_info_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		fso_audio_device_info_unref (value->data[0].v_pointer);
	}
}


static void fso_audio_value_device_info_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = fso_audio_device_info_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer fso_audio_value_device_info_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* fso_audio_value_device_info_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		FsoAudioDeviceInfo* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = fso_audio_device_info_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* fso_audio_value_device_info_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	FsoAudioDeviceInfo** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = fso_audio_device_info_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* fso_audio_param_spec_device_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	FsoAudioParamSpecDeviceInfo* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FSO_AUDIO_TYPE_DEVICE_INFO), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer fso_audio_value_get_device_info (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_AUDIO_TYPE_DEVICE_INFO), NULL);
	return value->data[0].v_pointer;
}


void fso_audio_value_set_device_info (GValue* value, gpointer v_object) {
	FsoAudioDeviceInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_AUDIO_TYPE_DEVICE_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_AUDIO_TYPE_DEVICE_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		fso_audio_device_info_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_audio_device_info_unref (old);
	}
}


void fso_audio_value_take_device_info (GValue* value, gpointer v_object) {
	FsoAudioDeviceInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_AUDIO_TYPE_DEVICE_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_AUDIO_TYPE_DEVICE_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_audio_device_info_unref (old);
	}
}


static void fso_audio_device_info_class_init (FsoAudioDeviceInfoClass * klass) {
	fso_audio_device_info_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_DEVICE_INFO_CLASS (klass)->finalize = fso_audio_device_info_finalize;
}


static void fso_audio_device_info_instance_init (FsoAudioDeviceInfo * self) {
	self->ref_count = 1;
}


static void fso_audio_device_info_finalize (FsoAudioDeviceInfo* obj) {
	FsoAudioDeviceInfo * self;
	self = FSO_AUDIO_DEVICE_INFO (obj);
	self->call_controls = (_vala_array_free (self->call_controls, self->call_controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
	self->normal_controls = (_vala_array_free (self->normal_controls, self->normal_controls_length1, (GDestroyNotify) fso_audio_control_info_unref), NULL);
}


/**
     * Saves controls for both modes normal and call and their states and offers a simple
     * API to manage them.
     **/
GType fso_audio_device_info_get_type (void) {
	return fso_audio_device_info_type_id;
}


GType fso_audio_device_info_register_type (GTypeModule * module) {
	static const GTypeValueTable g_define_type_value_table = { fso_audio_value_device_info_init, fso_audio_value_device_info_free_value, fso_audio_value_device_info_copy_value, fso_audio_value_device_info_peek_pointer, "p", fso_audio_value_device_info_collect_value, "p", fso_audio_value_device_info_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (FsoAudioDeviceInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_device_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioDeviceInfo), 0, (GInstanceInitFunc) fso_audio_device_info_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	fso_audio_device_info_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FsoAudioDeviceInfo", &g_define_type_info, &g_define_type_fundamental_info, 0);
	return fso_audio_device_info_type_id;
}


gpointer fso_audio_device_info_ref (gpointer instance) {
	FsoAudioDeviceInfo* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void fso_audio_device_info_unref (gpointer instance) {
	FsoAudioDeviceInfo* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FSO_AUDIO_DEVICE_INFO_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



