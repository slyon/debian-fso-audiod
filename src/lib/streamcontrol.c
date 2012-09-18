/* streamcontrol.c generated by valac 0.16.0, the Vala compiler
 * generated from streamcontrol.vala, do not modify */

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


#define FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL (fso_audio_abstract_stream_control_get_type ())
#define FSO_AUDIO_ABSTRACT_STREAM_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, FsoAudioAbstractStreamControl))
#define FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, FsoAudioAbstractStreamControlClass))
#define FSO_AUDIO_IS_ABSTRACT_STREAM_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL))
#define FSO_AUDIO_IS_ABSTRACT_STREAM_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL))
#define FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, FsoAudioAbstractStreamControlClass))

typedef struct _FsoAudioAbstractStreamControl FsoAudioAbstractStreamControl;
typedef struct _FsoAudioAbstractStreamControlClass FsoAudioAbstractStreamControlClass;
typedef struct _FsoAudioAbstractStreamControlPrivate FsoAudioAbstractStreamControlPrivate;

#define FSO_AUDIO_TYPE_NULL_STREAM_CONTROL (fso_audio_null_stream_control_get_type ())
#define FSO_AUDIO_NULL_STREAM_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_NULL_STREAM_CONTROL, FsoAudioNullStreamControl))
#define FSO_AUDIO_NULL_STREAM_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_NULL_STREAM_CONTROL, FsoAudioNullStreamControlClass))
#define FSO_AUDIO_IS_NULL_STREAM_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_NULL_STREAM_CONTROL))
#define FSO_AUDIO_IS_NULL_STREAM_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_NULL_STREAM_CONTROL))
#define FSO_AUDIO_NULL_STREAM_CONTROL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_NULL_STREAM_CONTROL, FsoAudioNullStreamControlClass))

typedef struct _FsoAudioNullStreamControl FsoAudioNullStreamControl;
typedef struct _FsoAudioNullStreamControlClass FsoAudioNullStreamControlClass;
typedef struct _FsoAudioNullStreamControlPrivate FsoAudioNullStreamControlPrivate;

struct _FsoAudioAbstractStreamControl {
	FsoFrameworkAbstractObject parent_instance;
	FsoAudioAbstractStreamControlPrivate * priv;
};

struct _FsoAudioAbstractStreamControlClass {
	FsoFrameworkAbstractObjectClass parent_class;
	void (*setup) (FsoAudioAbstractStreamControl* self);
	void (*set_mute) (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, gboolean mute);
	void (*set_volume) (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, guint level);
	gboolean (*get_mute) (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream);
	guint (*get_volume) (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream);
};

struct _FsoAudioNullStreamControl {
	FsoAudioAbstractStreamControl parent_instance;
	FsoAudioNullStreamControlPrivate * priv;
};

struct _FsoAudioNullStreamControlClass {
	FsoAudioAbstractStreamControlClass parent_class;
};


static gpointer fso_audio_abstract_stream_control_parent_class = NULL;
static gpointer fso_audio_null_stream_control_parent_class = NULL;

GType fso_audio_abstract_stream_control_get_type (void) G_GNUC_CONST;
enum  {
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_DUMMY_PROPERTY
};
void fso_audio_abstract_stream_control_setup (FsoAudioAbstractStreamControl* self);
static void fso_audio_abstract_stream_control_real_setup (FsoAudioAbstractStreamControl* self);
void fso_audio_abstract_stream_control_set_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, gboolean mute);
static void fso_audio_abstract_stream_control_real_set_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, gboolean mute);
void fso_audio_abstract_stream_control_set_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, guint level);
static void fso_audio_abstract_stream_control_real_set_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, guint level);
gboolean fso_audio_abstract_stream_control_get_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream);
static gboolean fso_audio_abstract_stream_control_real_get_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream);
guint fso_audio_abstract_stream_control_get_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream);
static guint fso_audio_abstract_stream_control_real_get_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream);
static gchar* fso_audio_abstract_stream_control_real_repr (FsoFrameworkAbstractObject* base);
FsoAudioAbstractStreamControl* fso_audio_abstract_stream_control_construct (GType object_type);
static void g_cclosure_user_marshal_VOID__ENUM_UINT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void g_cclosure_user_marshal_VOID__ENUM_BOOLEAN (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
GType fso_audio_null_stream_control_get_type (void) G_GNUC_CONST;
enum  {
	FSO_AUDIO_NULL_STREAM_CONTROL_DUMMY_PROPERTY
};
static void fso_audio_null_stream_control_real_setup (FsoAudioAbstractStreamControl* base);
static void fso_audio_null_stream_control_real_set_mute (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream, gboolean mute);
static void fso_audio_null_stream_control_real_set_volume (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream, guint level);
static gboolean fso_audio_null_stream_control_real_get_mute (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream);
static guint fso_audio_null_stream_control_real_get_volume (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream);
FsoAudioNullStreamControl* fso_audio_null_stream_control_new (void);
FsoAudioNullStreamControl* fso_audio_null_stream_control_construct (GType object_type);


/**
         * Setup up various apsects of the the stream control
         **/
static void fso_audio_abstract_stream_control_real_setup (FsoAudioAbstractStreamControl* self) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_stream_control_setup'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_audio_abstract_stream_control_setup (FsoAudioAbstractStreamControl* self) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS (self)->setup (self);
}


static void fso_audio_abstract_stream_control_real_set_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, gboolean mute) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_stream_control_set_mute'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_audio_abstract_stream_control_set_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, gboolean mute) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS (self)->set_mute (self, stream, mute);
}


static void fso_audio_abstract_stream_control_real_set_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, guint level) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_stream_control_set_volume'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_audio_abstract_stream_control_set_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream, guint level) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS (self)->set_volume (self, stream, level);
}


static gboolean fso_audio_abstract_stream_control_real_get_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_stream_control_get_mute'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return FALSE;
}


gboolean fso_audio_abstract_stream_control_get_mute (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream) {
	g_return_val_if_fail (self != NULL, FALSE);
	return FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS (self)->get_mute (self, stream);
}


static guint fso_audio_abstract_stream_control_real_get_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_stream_control_get_volume'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0U;
}


guint fso_audio_abstract_stream_control_get_volume (FsoAudioAbstractStreamControl* self, FreeSmartphoneAudioStream stream) {
	g_return_val_if_fail (self != NULL, 0U);
	return FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS (self)->get_volume (self, stream);
}


static gchar* fso_audio_abstract_stream_control_real_repr (FsoFrameworkAbstractObject* base) {
	FsoAudioAbstractStreamControl * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoAudioAbstractStreamControl*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


FsoAudioAbstractStreamControl* fso_audio_abstract_stream_control_construct (GType object_type) {
	FsoAudioAbstractStreamControl * self = NULL;
	self = (FsoAudioAbstractStreamControl*) fso_framework_abstract_object_construct (object_type);
	return self;
}


static void g_cclosure_user_marshal_VOID__ENUM_UINT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__ENUM_UINT) (gpointer data1, gint arg_1, guint arg_2, gpointer data2);
	register GMarshalFunc_VOID__ENUM_UINT callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__ENUM_UINT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_enum (param_values + 1), g_value_get_uint (param_values + 2), data2);
}


static void g_cclosure_user_marshal_VOID__ENUM_BOOLEAN (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__ENUM_BOOLEAN) (gpointer data1, gint arg_1, gboolean arg_2, gpointer data2);
	register GMarshalFunc_VOID__ENUM_BOOLEAN callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__ENUM_BOOLEAN) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_enum (param_values + 1), g_value_get_boolean (param_values + 2), data2);
}


static void fso_audio_abstract_stream_control_class_init (FsoAudioAbstractStreamControlClass * klass) {
	fso_audio_abstract_stream_control_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->setup = fso_audio_abstract_stream_control_real_setup;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->set_mute = fso_audio_abstract_stream_control_real_set_mute;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->set_volume = fso_audio_abstract_stream_control_real_set_volume;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->get_mute = fso_audio_abstract_stream_control_real_get_mute;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->get_volume = fso_audio_abstract_stream_control_real_get_volume;
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_audio_abstract_stream_control_real_repr;
	g_signal_new ("volume_changed", FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__ENUM_UINT, G_TYPE_NONE, 2, FREE_SMARTPHONE_AUDIO_TYPE_STREAM, G_TYPE_UINT);
	g_signal_new ("mute_changed", FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__ENUM_BOOLEAN, G_TYPE_NONE, 2, FREE_SMARTPHONE_AUDIO_TYPE_STREAM, G_TYPE_BOOLEAN);
}


static void fso_audio_abstract_stream_control_instance_init (FsoAudioAbstractStreamControl * self) {
}


GType fso_audio_abstract_stream_control_get_type (void) {
	static volatile gsize fso_audio_abstract_stream_control_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_abstract_stream_control_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioAbstractStreamControlClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_abstract_stream_control_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioAbstractStreamControl), 0, (GInstanceInitFunc) fso_audio_abstract_stream_control_instance_init, NULL };
		GType fso_audio_abstract_stream_control_type_id;
		fso_audio_abstract_stream_control_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoAudioAbstractStreamControl", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&fso_audio_abstract_stream_control_type_id__volatile, fso_audio_abstract_stream_control_type_id);
	}
	return fso_audio_abstract_stream_control_type_id__volatile;
}


static void fso_audio_null_stream_control_real_setup (FsoAudioAbstractStreamControl* base) {
	FsoAudioNullStreamControl * self;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullStreamControl*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullStreamControl::setup(): This is probably not what you want!");
}


static void fso_audio_null_stream_control_real_set_mute (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream, gboolean mute) {
	FsoAudioNullStreamControl * self;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullStreamControl*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullStreamControl::set_mute(): This is probably not what you want!");
}


static void fso_audio_null_stream_control_real_set_volume (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream, guint level) {
	FsoAudioNullStreamControl * self;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullStreamControl*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullStreamControl::set_volume(): This is probably not what you want!");
}


static gboolean fso_audio_null_stream_control_real_get_mute (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream) {
	FsoAudioNullStreamControl * self;
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullStreamControl*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullStreamControl::get_mute(): This is probably not what you want!");
	result = FALSE;
	return result;
}


static guint fso_audio_null_stream_control_real_get_volume (FsoAudioAbstractStreamControl* base, FreeSmartphoneAudioStream stream) {
	FsoAudioNullStreamControl * self;
	guint result = 0U;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullStreamControl*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullStreamControl::get_volume(): This is probably not what you want!");
	result = (guint) 100;
	return result;
}


FsoAudioNullStreamControl* fso_audio_null_stream_control_construct (GType object_type) {
	FsoAudioNullStreamControl * self = NULL;
	self = (FsoAudioNullStreamControl*) fso_audio_abstract_stream_control_construct (object_type);
	return self;
}


FsoAudioNullStreamControl* fso_audio_null_stream_control_new (void) {
	return fso_audio_null_stream_control_construct (FSO_AUDIO_TYPE_NULL_STREAM_CONTROL);
}


static void fso_audio_null_stream_control_class_init (FsoAudioNullStreamControlClass * klass) {
	fso_audio_null_stream_control_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->setup = fso_audio_null_stream_control_real_setup;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->set_mute = fso_audio_null_stream_control_real_set_mute;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->set_volume = fso_audio_null_stream_control_real_set_volume;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->get_mute = fso_audio_null_stream_control_real_get_mute;
	FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS (klass)->get_volume = fso_audio_null_stream_control_real_get_volume;
}


static void fso_audio_null_stream_control_instance_init (FsoAudioNullStreamControl * self) {
}


GType fso_audio_null_stream_control_get_type (void) {
	static volatile gsize fso_audio_null_stream_control_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_null_stream_control_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioNullStreamControlClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_null_stream_control_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioNullStreamControl), 0, (GInstanceInitFunc) fso_audio_null_stream_control_instance_init, NULL };
		GType fso_audio_null_stream_control_type_id;
		fso_audio_null_stream_control_type_id = g_type_register_static (FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, "FsoAudioNullStreamControl", &g_define_type_info, 0);
		g_once_init_leave (&fso_audio_null_stream_control_type_id__volatile, fso_audio_null_stream_control_type_id);
	}
	return fso_audio_null_stream_control_type_id__volatile;
}


