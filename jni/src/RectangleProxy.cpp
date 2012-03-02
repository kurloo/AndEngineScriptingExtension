#include "RectangleProxy.h"

// ===========================================================
// org.andengine.extension.scripting.entity.primitive.RectangleProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	RectangleProxy* rectangle = (RectangleProxy*)pAddress;

	return rectangle->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	RectangleProxy* rectangle = (RectangleProxy*)pAddress;

	return rectangle->onDetached();
}


RectangleProxy::RectangleProxy() {
	/* Intentionally empty. */
}

RectangleProxy::RectangleProxy(float pX, float pY, float pWidth, float pHeight, jobject pVertexBufferObjectManager) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/extension/scripting/entity/primitive/RectangleProxy");

	jmethodID constructor = JNI_ENV()->GetMethodID(clazz, "<init>", "(JFFFFLorg/andengine/opengl/vbo/VertexBufferObjectManager;)V");

	this->mUnwrapped = JNI_ENV()->NewObject(clazz, constructor, this, pX, pY, pWidth, pHeight, pVertexBufferObjectManager);
}
