#ifndef ADAPT_CLANG_SERVICE__ADAPT_SERVICE_H
#define ADAPT_CLANG_SERVICE__ADAPT_SERVICE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(_WIN32)
#ifdef ADAPT_SERVICE_DLL
#define ADAPT_SERVICE_API __declspec(dllexport)
#else
#define ADAPT_SERVICE_API __declspec(dllimport)
#endif
#else
#define ADAPT_SERVICE_API
#endif

#define ADAPT_PACKAGE_ZIP 0
#define ADAPT_PACKAGE_SINGLE_FILE 1
#define ADAPT_PACKAGE_FILE_SYSTEM 2
    
typedef struct adapt_callback {
    unsigned long content_length;
    int packaging_type;
    const char* base_path;  /* File types that reference other resources, i.e. OPF and XHTML */
    void (*read_bytes)(struct adapt_callback* self, void* buffer, size_t offset, size_t length);
    void (*process_message)(struct adapt_callback* self, const void* buffer, size_t length);
} adapt_callback;

typedef struct adapt_serving_context adapt_serving_context;

ADAPT_SERVICE_API adapt_serving_context* adapt_start_serving(adapt_callback* callback);
ADAPT_SERVICE_API const char* adapt_get_bootstrap_url(adapt_serving_context* context);
ADAPT_SERVICE_API void adapt_update_base_path_xml(adapt_serving_context* context);
ADAPT_SERVICE_API const char* adapt_get_init_call(adapt_serving_context* context, const char* instance_id, const char* extra_config);
ADAPT_SERVICE_API void adapt_stop_serving(adapt_serving_context*);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ADAPT_CLANG_SERVICE__ADAPT_SERVICE_H */
