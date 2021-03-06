/* controlinfo.c generated by valac 0.16.1, the Vala compiler
 * generated from controlinfo.vala, do not modify */

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


#define FSO_AUDIO_TYPE_CONTROL_INFO (fso_audio_control_info_get_type ())
#define FSO_AUDIO_CONTROL_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_CONTROL_INFO, FsoAudioControlInfo))
#define FSO_AUDIO_CONTROL_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_CONTROL_INFO, FsoAudioControlInfoClass))
#define FSO_AUDIO_IS_CONTROL_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_CONTROL_INFO))
#define FSO_AUDIO_IS_CONTROL_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_CONTROL_INFO))
#define FSO_AUDIO_CONTROL_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_CONTROL_INFO, FsoAudioControlInfoClass))

typedef struct _FsoAudioControlInfo FsoAudioControlInfo;
typedef struct _FsoAudioControlInfoClass FsoAudioControlInfoClass;
typedef struct _FsoAudioControlInfoPrivate FsoAudioControlInfoPrivate;
typedef struct _FsoAudioParamSpecControlInfo FsoAudioParamSpecControlInfo;

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

struct _FsoAudioParamSpecControlInfo {
	GParamSpec parent_instance;
};


static gpointer fso_audio_control_info_parent_class = NULL;
static GType fso_audio_control_info_type_id = 0;

gpointer fso_audio_control_info_ref (gpointer instance);
void fso_audio_control_info_unref (gpointer instance);
GParamSpec* fso_audio_param_spec_control_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_audio_value_set_control_info (GValue* value, gpointer v_object);
void fso_audio_value_take_control_info (GValue* value, gpointer v_object);
gpointer fso_audio_value_get_control_info (const GValue* value);
GType fso_audio_control_info_get_type (void) G_GNUC_CONST;
GType fso_audio_control_info_register_type (GTypeModule * module);
enum  {
	FSO_AUDIO_CONTROL_INFO_DUMMY_PROPERTY
};
FsoAudioControlInfo* fso_audio_control_info_new (FreeSmartphoneAudioControl type, gint volume);
FsoAudioControlInfo* fso_audio_control_info_construct (GType object_type, FreeSmartphoneAudioControl type, gint volume);
static void fso_audio_control_info_finalize (FsoAudioControlInfo* obj);


FsoAudioControlInfo* fso_audio_control_info_construct (GType object_type, FreeSmartphoneAudioControl type, gint volume) {
	FsoAudioControlInfo* self = NULL;
	FreeSmartphoneAudioControl _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	self = (FsoAudioControlInfo*) g_type_create_instance (object_type);
	_tmp0_ = type;
	self->type = _tmp0_;
	_tmp1_ = volume;
	self->volume = _tmp1_;
	_tmp2_ = self->volume;
	self->muted = _tmp2_ == 0;
	return self;
}


FsoAudioControlInfo* fso_audio_control_info_new (FreeSmartphoneAudioControl type, gint volume) {
	return fso_audio_control_info_construct (FSO_AUDIO_TYPE_CONTROL_INFO, type, volume);
}


static void fso_audio_value_control_info_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void fso_audio_value_control_info_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		fso_audio_control_info_unref (value->data[0].v_pointer);
	}
}


static void fso_audio_value_control_info_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = fso_audio_control_info_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer fso_audio_value_control_info_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* fso_audio_value_control_info_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		FsoAudioControlInfo* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = fso_audio_control_info_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* fso_audio_value_control_info_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	FsoAudioControlInfo** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = fso_audio_control_info_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* fso_audio_param_spec_control_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	FsoAudioParamSpecControlInfo* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FSO_AUDIO_TYPE_CONTROL_INFO), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer fso_audio_value_get_control_info (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_AUDIO_TYPE_CONTROL_INFO), NULL);
	return value->data[0].v_pointer;
}


void fso_audio_value_set_control_info (GValue* value, gpointer v_object) {
	FsoAudioControlInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_AUDIO_TYPE_CONTROL_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_AUDIO_TYPE_CONTROL_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		fso_audio_control_info_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_audio_control_info_unref (old);
	}
}


void fso_audio_value_take_control_info (GValue* value, gpointer v_object) {
	FsoAudioControlInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_AUDIO_TYPE_CONTROL_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_AUDIO_TYPE_CONTROL_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_audio_control_info_unref (old);
	}
}


static void fso_audio_control_info_class_init (FsoAudioControlInfoClass * klass) {
	fso_audio_control_info_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_CONTROL_INFO_CLASS (klass)->finalize = fso_audio_control_info_finalize;
}


static void fso_audio_control_info_instance_init (FsoAudioControlInfo * self) {
	self->ref_count = 1;
}


static void fso_audio_control_info_finalize (FsoAudioControlInfo* obj) {
	FsoAudioControlInfo * self;
	self = FSO_AUDIO_CONTROL_INFO (obj);
}


/**
     * Information about a simple control like volume, mute status.
     **/
GType fso_audio_control_info_get_type (void) {
	return fso_audio_control_info_type_id;
}


GType fso_audio_control_info_register_type (GTypeModule * module) {
	static const GTypeValueTable g_define_type_value_table = { fso_audio_value_control_info_init, fso_audio_value_control_info_free_value, fso_audio_value_control_info_copy_value, fso_audio_value_control_info_peek_pointer, "p", fso_audio_value_control_info_collect_value, "p", fso_audio_value_control_info_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (FsoAudioControlInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_control_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioControlInfo), 0, (GInstanceInitFunc) fso_audio_control_info_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	fso_audio_control_info_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FsoAudioControlInfo", &g_define_type_info, &g_define_type_fundamental_info, 0);
	return fso_audio_control_info_type_id;
}


gpointer fso_audio_control_info_ref (gpointer instance) {
	FsoAudioControlInfo* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void fso_audio_control_info_unref (gpointer instance) {
	FsoAudioControlInfo* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FSO_AUDIO_CONTROL_INFO_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



