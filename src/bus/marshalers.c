#include "marshalers.h"
#include <glib-object.h>

#ifdef G_ENABLE_DEBUG
#define g_marshal_value_peek_boolean(v)  g_value_get_boolean (v)
#define g_marshal_value_peek_char(v)     g_value_get_schar (v)
#define g_marshal_value_peek_uchar(v)    g_value_get_uchar (v)
#define g_marshal_value_peek_int(v)      g_value_get_int (v)
#define g_marshal_value_peek_uint(v)     g_value_get_uint (v)
#define g_marshal_value_peek_long(v)     g_value_get_long (v)
#define g_marshal_value_peek_ulong(v)    g_value_get_ulong (v)
#define g_marshal_value_peek_int64(v)    g_value_get_int64 (v)
#define g_marshal_value_peek_uint64(v)   g_value_get_uint64 (v)
#define g_marshal_value_peek_enum(v)     g_value_get_enum (v)
#define g_marshal_value_peek_flags(v)    g_value_get_flags (v)
#define g_marshal_value_peek_float(v)    g_value_get_float (v)
#define g_marshal_value_peek_double(v)   g_value_get_double (v)
#define g_marshal_value_peek_string(v)   (char*) g_value_get_string (v)
#define g_marshal_value_peek_param(v)    g_value_get_param (v)
#define g_marshal_value_peek_boxed(v)    g_value_get_boxed (v)
#define g_marshal_value_peek_pointer(v)  g_value_get_pointer (v)
#define g_marshal_value_peek_object(v)   g_value_get_object (v)
#define g_marshal_value_peek_variant(v)  g_value_get_variant (v)
#else /* !G_ENABLE_DEBUG */
/* WARNING: This code accesses GValues directly, which is UNSUPPORTED API.
 *          Do not access GValues directly in your code. Instead, use the
 *          g_value_get_*() functions
 */
#define g_marshal_value_peek_boolean(v)  (v)->data[0].v_int
#define g_marshal_value_peek_char(v)     (v)->data[0].v_int
#define g_marshal_value_peek_uchar(v)    (v)->data[0].v_uint
#define g_marshal_value_peek_int(v)      (v)->data[0].v_int
#define g_marshal_value_peek_uint(v)     (v)->data[0].v_uint
#define g_marshal_value_peek_long(v)     (v)->data[0].v_long
#define g_marshal_value_peek_ulong(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_int64(v)    (v)->data[0].v_int64
#define g_marshal_value_peek_uint64(v)   (v)->data[0].v_uint64
#define g_marshal_value_peek_enum(v)     (v)->data[0].v_long
#define g_marshal_value_peek_flags(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_float(v)    (v)->data[0].v_float
#define g_marshal_value_peek_double(v)   (v)->data[0].v_double
#define g_marshal_value_peek_string(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_param(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_boxed(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_pointer(v)  (v)->data[0].v_pointer
#define g_marshal_value_peek_object(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_variant(v)  (v)->data[0].v_pointer
#endif /* !G_ENABLE_DEBUG */

/* BOOL:UINT,UINT,UINT (./marshalers.list:1) */
void
bus_marshal_BOOLEAN__UINT_UINT_UINT (GClosure     *closure,
                                     GValue       *return_value,
                                     guint         n_param_values,
                                     const GValue *param_values,
                                     gpointer      invocation_hint G_GNUC_UNUSED,
                                     gpointer      marshal_data)
{
  typedef gboolean (*GMarshalFunc_BOOLEAN__UINT_UINT_UINT) (gpointer data1,
                                                            guint arg1,
                                                            guint arg2,
                                                            guint arg3,
                                                            gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_BOOLEAN__UINT_UINT_UINT callback;
  gboolean v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_BOOLEAN__UINT_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_uint (param_values + 1),
                       g_marshal_value_peek_uint (param_values + 2),
                       g_marshal_value_peek_uint (param_values + 3),
                       data2);

  g_value_set_boolean (return_value, v_return);
}

/* OBJECT:STRING (./marshalers.list:2) */
void
bus_marshal_OBJECT__STRING (GClosure     *closure,
                            GValue       *return_value,
                            guint         n_param_values,
                            const GValue *param_values,
                            gpointer      invocation_hint G_GNUC_UNUSED,
                            gpointer      marshal_data)
{
  typedef GObject* (*GMarshalFunc_OBJECT__STRING) (gpointer data1,
                                                   gpointer arg1,
                                                   gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_OBJECT__STRING callback;
  GObject* v_return;

  g_return_if_fail (return_value != NULL);
  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_OBJECT__STRING) (marshal_data ? marshal_data : cc->callback);

  v_return = callback (data1,
                       g_marshal_value_peek_string (param_values + 1),
                       data2);

  g_value_take_object (return_value, v_return);
}

/* VOID:INT,UINT (./marshalers.list:3) */
void
bus_marshal_VOID__INT_UINT (GClosure     *closure,
                            GValue       *return_value G_GNUC_UNUSED,
                            guint         n_param_values,
                            const GValue *param_values,
                            gpointer      invocation_hint G_GNUC_UNUSED,
                            gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_UINT) (gpointer data1,
                                               gint arg1,
                                               guint arg2,
                                               gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__INT_UINT callback;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}

/* VOID:INT,INT,INT,INT (./marshalers.list:4) */
void
bus_marshal_VOID__INT_INT_INT_INT (GClosure     *closure,
                                   GValue       *return_value G_GNUC_UNUSED,
                                   guint         n_param_values,
                                   const GValue *param_values,
                                   gpointer      invocation_hint G_GNUC_UNUSED,
                                   gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_INT_INT_INT) (gpointer data1,
                                                      gint arg1,
                                                      gint arg2,
                                                      gint arg3,
                                                      gint arg4,
                                                      gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__INT_INT_INT_INT callback;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT_INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            g_marshal_value_peek_int (param_values + 3),
            g_marshal_value_peek_int (param_values + 4),
            data2);
}

/* VOID:OBJECT (./marshalers.list:5) */
void
bus_marshal_VOID__OBJECT (GClosure     *closure,
                          GValue       *return_value G_GNUC_UNUSED,
                          guint         n_param_values,
                          const GValue *param_values,
                          gpointer      invocation_hint G_GNUC_UNUSED,
                          gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT) (gpointer data1,
                                             gpointer arg1,
                                             gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT callback;

  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            data2);
}

/* VOID:OBJECT,BOOLEAN (./marshalers.list:6) */
void
bus_marshal_VOID__OBJECT_BOOLEAN (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_BOOLEAN) (gpointer data1,
                                                     gpointer arg1,
                                                     gboolean arg2,
                                                     gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_BOOLEAN callback;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_boolean (param_values + 2),
            data2);
}

/* VOID:OBJECT,STRING (./marshalers.list:7) */
void
bus_marshal_VOID__OBJECT_STRING (GClosure     *closure,
                                 GValue       *return_value G_GNUC_UNUSED,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING) (gpointer data1,
                                                    gpointer arg1,
                                                    gpointer arg2,
                                                    gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_STRING callback;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}

/* VOID:OBJECT,UINT,BOOLEAN (./marshalers.list:8) */
void
bus_marshal_VOID__OBJECT_UINT_BOOLEAN (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT_BOOLEAN) (gpointer data1,
                                                          gpointer arg1,
                                                          guint arg2,
                                                          gboolean arg3,
                                                          gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_UINT_BOOLEAN callback;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT_BOOLEAN) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            data2);
}

/* VOID:OBJECT,UINT,BOOLEAN,UINT (./marshalers.list:9) */
void
bus_marshal_VOID__OBJECT_UINT_BOOLEAN_UINT (GClosure     *closure,
                                            GValue       *return_value G_GNUC_UNUSED,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint G_GNUC_UNUSED,
                                            gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT_BOOLEAN_UINT) (gpointer data1,
                                                               gpointer arg1,
                                                               guint arg2,
                                                               gboolean arg3,
                                                               guint arg4,
                                                               gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_UINT_BOOLEAN_UINT callback;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT_BOOLEAN_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_boolean (param_values + 3),
            g_marshal_value_peek_uint (param_values + 4),
            data2);
}

/* VOID:OBJECT,STRING,STRING,STRING (./marshalers.list:10) */
void
bus_marshal_VOID__OBJECT_STRING_STRING_STRING (GClosure     *closure,
                                               GValue       *return_value G_GNUC_UNUSED,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint G_GNUC_UNUSED,
                                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING_STRING_STRING) (gpointer data1,
                                                                  gpointer arg1,
                                                                  gpointer arg2,
                                                                  gpointer arg3,
                                                                  gpointer arg4,
                                                                  gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__OBJECT_STRING_STRING_STRING callback;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_string (param_values + 3),
            g_marshal_value_peek_string (param_values + 4),
            data2);
}

/* VOID:STRING (./marshalers.list:11) */
void
bus_marshal_VOID__STRING (GClosure     *closure,
                          GValue       *return_value G_GNUC_UNUSED,
                          guint         n_param_values,
                          const GValue *param_values,
                          gpointer      invocation_hint G_GNUC_UNUSED,
                          gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING) (gpointer data1,
                                             gpointer arg1,
                                             gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING callback;

  g_return_if_fail (n_param_values == 2);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            data2);
}

/* VOID:STRING,INT (./marshalers.list:12) */
void
bus_marshal_VOID__STRING_INT (GClosure     *closure,
                              GValue       *return_value G_GNUC_UNUSED,
                              guint         n_param_values,
                              const GValue *param_values,
                              gpointer      invocation_hint G_GNUC_UNUSED,
                              gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_INT) (gpointer data1,
                                                 gpointer arg1,
                                                 gint arg2,
                                                 gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__STRING_INT callback;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            data2);
}

/* VOID:UINT,UINT (./marshalers.list:13) */
void
bus_marshal_VOID__UINT_UINT (GClosure     *closure,
                             GValue       *return_value G_GNUC_UNUSED,
                             guint         n_param_values,
                             const GValue *param_values,
                             gpointer      invocation_hint G_GNUC_UNUSED,
                             gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT) (gpointer data1,
                                                guint arg1,
                                                guint arg2,
                                                gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_UINT callback;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}

/* VOID:UINT,UINT,UINT (./marshalers.list:14) */
void
bus_marshal_VOID__UINT_UINT_UINT (GClosure     *closure,
                                  GValue       *return_value G_GNUC_UNUSED,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT_UINT) (gpointer data1,
                                                     guint arg1,
                                                     guint arg2,
                                                     guint arg3,
                                                     gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__UINT_UINT_UINT callback;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            data2);
}

/* VOID:VOID (./marshalers.list:15) */
void
bus_marshal_VOID__VOID (GClosure     *closure,
                        GValue       *return_value G_GNUC_UNUSED,
                        guint         n_param_values,
                        const GValue *param_values,
                        gpointer      invocation_hint G_GNUC_UNUSED,
                        gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__VOID) (gpointer data1,
                                           gpointer data2);
  GCClosure *cc = (GCClosure *) closure;
  gpointer data1, data2;
  GMarshalFunc_VOID__VOID callback;

  g_return_if_fail (n_param_values == 1);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__VOID) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            data2);
}

