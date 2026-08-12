/* Fallback Vulkan loader alias for loaderless NVK static linking.
 * When Mesa's libvulkan.a is built as ICD only (no vkGetInstanceProcAddr),
 * PPSSPP's VulkanLoader expects the public name. Provide it as a thin
 * wrapper over vk_icdGetInstanceProcAddr, which the ICD does export. */
typedef void (*PFN_vkVoidFunction)(void);
PFN_vkVoidFunction vk_icdGetInstanceProcAddr(void* instance, const char* name);
PFN_vkVoidFunction vkGetInstanceProcAddr(void* instance, const char* name) {
    return vk_icdGetInstanceProcAddr(instance, name);
}
