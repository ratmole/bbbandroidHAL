/**********************************************************
  JNI general purpose interface code for bbbandroidHAL

  Written by Ankur Yadav (ankurayadav@gmail.com)

  This code is made available under the BSD license.
**********************************************************/

/**
 * @file jni_wrapper.c
 * @author Ankur Yadav (ankurayadav@gmail.com)
 * @brief JNI general purpose interface code for bbbandroidHAL
 */

#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <android/log.h>

#include "bbbandroidHAL.h"

#define JAVA_CLASS_PATH(funtion_name) Java_com_bbbandroid_gpio_MainActivity_##funtion_name

#define BBBANDROID_NATIVE_TAG "NDK_BBBAndroidApplication"
#define BUFFER_SIZE 64

/* Begin the JNI wrapper functions for the GPIO app */
jboolean JAVA_CLASS_PATH(openGPIO)(JNIEnv *env, jobject this)
{
	jboolean ret = JNI_TRUE;
	if ( openGPIO(0) == 0 ) {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "GPIO Opened.");
	} else {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "openGPIO() failed!");
		ret = JNI_FALSE;
	}
	return ret;
}

void JAVA_CLASS_PATH(closeGPIO)(JNIEnv *env, jobject this)
{
	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "GPIO closing...");
	closeGPIO();
}

jboolean JAVA_CLASS_PATH(readGPIO)(JNIEnv *env, jobject this, jint header, jint pin)
{
	int ret = readGPIO((unsigned int) header, (unsigned int) pin);
	__android_log_print(ANDROID_LOG_DEBUG,
			BBBANDROID_NATIVE_TAG,
			"readGPIO(%d, %d) == %d", (unsigned int) header, (unsigned int) pin, ret);
	return ret == 0 ? JNI_FALSE : JNI_TRUE;
}

void JAVA_CLASS_PATH(writeGPIO)(JNIEnv *env, jobject this, jint header, jint pin, jint val)
{
	int ret = writeGPIO((unsigned int) header, (unsigned int) pin, (unsigned int) val);
	__android_log_print(ANDROID_LOG_DEBUG,
			BBBANDROID_NATIVE_TAG,
			"writeGPIO(%d, %d, %d) == %d", (unsigned int) header, (unsigned int) pin, (unsigned int) val, ret);
}
/* End the JNI wrapper functions for the GPIO app */

/* Begin the JNI wrapper functions for the PWM app */
jboolean JAVA_CLASS_PATH(pwmSetPeriod)(JNIEnv *env, jobject this, jint channel, jint period_ns)
{
	jint ret;
	ret = pwmSetPeriod(channel, period_ns) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmSetPeriod(%d, %d) failed!", (unsigned int) channel, (unsigned int) period_ns);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmSetPeriod(%d, %d) succeeded", (unsigned int) channel, (unsigned int) period_ns);
	}

	return JNI_TRUE;
}

jint JAVA_CLASS_PATH(pwmGetPeriod)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = pwmGetPeriod(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmGetPeriod(%d) failed!", (unsigned int) channel);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmGetPeriod(%d) succeeded", (unsigned int) channel);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(pwmSetDutyCycle)(JNIEnv *env, jobject this, jint channel, jint duration_ns)
{
	jint ret;
	ret = pwmSetDutyCycle(channel, duration_ns) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmSetDutyCycle(%d, %d) failed!", (unsigned int) channel, (unsigned int) duration_ns);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmSetDutyCycle(%d, %d) succeeded", (unsigned int) channel, (unsigned int) duration_ns);
	}

	return JNI_TRUE;
}

jint JAVA_CLASS_PATH(pwmGetDutyCycle)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = pwmGetDutyCycle(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmGetDutyCycle(%d) failed!", (unsigned int) channel);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmGetDutyCycle(%d) succeeded", (unsigned int) channel);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(pwmSetPolarity)(JNIEnv *env, jobject this, jint channel, jint polarity)
{
	jint ret;
	ret = pwmSetPolarity(channel, polarity) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmSetPolarity(%d, %d) failed!", (unsigned int) channel, (unsigned int) polarity);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmSetPolarity(%d, %d) succeeded", (unsigned int) channel, (unsigned int) polarity);
	}

	return JNI_TRUE;
}

jint JAVA_CLASS_PATH(pwmGetPolarity)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = pwmGetPolarity(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmGetPolarity(%d) failed!", (unsigned int) channel);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmGetPolarity(%d) succeeded", (unsigned int) channel);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(pwmRun)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = pwmRun(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmRun(%d) failed!", (unsigned int) channel);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmRun(%d) succeeded", (unsigned int) channel);
	}

	return JNI_TRUE;
}

jboolean JAVA_CLASS_PATH(pwmStop)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = pwmStop(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmStop(%d) failed!", (unsigned int) channel);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmStop(%d) succeeded", (unsigned int) channel);
	}

	return JNI_TRUE;
}

jint JAVA_CLASS_PATH(pwmRunCheck)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = pwmRunCheck(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "pwmRunCheck(%d) failed!", (unsigned int) channel);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "pwmRunCheck(%d) succeeded", (unsigned int) channel);
	}

	return ret;
}

/* End the JNI wrapper functions for the PWM app */

/* Begin the JNI wrapper functions for the ADC app */

jint JAVA_CLASS_PATH(readADC)(JNIEnv *env, jobject this, jint channel)
{
	jint ret;
	ret = readADC(channel) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "readADC(%d) failed!", (unsigned int) channel);
		ret = -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "readADC(%d) succeeded", (unsigned int) channel);
	}

	return ret;
}

/* End the JNI wrapper funtions for the ADC app */

/* Begin the JNI wrapper functions for the I2C app */

jint JAVA_CLASS_PATH(i2cOpenAdaptor)(JNIEnv *env, jobject this, jint adaptorNumber)
{
	jint ret;
	ret = i2cOpenAdaptor(adaptorNumber) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "i2cOpenAdaptor(%d) failed!", (unsigned int) adaptorNumber);
		ret = -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cOpenAdaptor(%d) succeeded", (unsigned int) adaptorNumber);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(i2cSetSlave)(JNIEnv *env, jobject this, jint i2cFD, jint address)
{
	jint ret;
	ret = i2cSetSlave(i2cFD, address) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "i2cSetSlave(%d, %d) failed!", (unsigned int) i2cFD, (unsigned int) address);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cSetSlave(%d, %d) succeeded", (unsigned int) i2cFD, (unsigned int) address);
	}

	return JNI_TRUE;
}

jboolean JAVA_CLASS_PATH(i2cWriteByte)(JNIEnv *env, jobject this, jint i2cFD, jbyte add, jbyte byte)
{
	jint ret;
	ret = i2cWriteByte(i2cFD, add, byte) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "i2cWriteByte(%d, %d, %d) failed!", (unsigned int) i2cFD, (unsigned int) add, (unsigned int) byte);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cWriteByte(%d, %d, %d) succeeded", (unsigned int) i2cFD, (unsigned int) add, (unsigned int) byte);
	}

	return JNI_TRUE;
}

jboolean JAVA_CLASS_PATH(i2cWriteBytes)(JNIEnv *env, jobject this, jint i2cFD,jbyte add, jint length, jbyteArray barray)
{
	jint ret;
	int i;

	jbyte* bufferPtr = (*env)->GetByteArrayElements(env, barray, NULL);

	uint8_t bytes[length] ;

	for(i=0; i<length; i++)
	{
		bytes[i] = bufferPtr[i];
	}

	(*env)->ReleaseByteArrayElements(env, barray, bufferPtr, 0);

	ret = i2cWriteBytes(i2cFD, add, length, bytes) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "i2cWriteBytes(%d, %d, %d, bytearray) failed!", (unsigned int) i2cFD, (unsigned int) add, (unsigned int) length);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cWriteBytes(%d, %d, %d, bytearray) succeeded", (unsigned int) i2cFD, (unsigned int) add, (unsigned int) length);
	}

	return JNI_TRUE;
}

jint JAVA_CLASS_PATH(i2cReadByte)(JNIEnv *env, jobject this, jint i2cFD, jbyte add)
{
	jint ret;
	ret = i2cReadByte(i2cFD, add) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "i2cReadByte(%d, %d) failed!", (unsigned int) i2cFD, (unsigned int) add);
		return -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cReadByte(%d, %d) succeeded", (unsigned int) i2cFD, (unsigned int) add);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(i2cReadBytes)(JNIEnv *env, jobject this, jint i2cFD, jbyte add, jint length, jintArray barray)
{
	jint ret;
	int i;
	uint8_t bytes[length] ;

	ret = i2cReadBytes(i2cFD, add, length, bytes) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "i2cReadBytes(%d, %d, %d, bytearray) failed!", (unsigned int) i2cFD, (unsigned int) add, (unsigned int) length);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cReadBytes(%d, %d, %d, bytearray) succeeded", (unsigned int) i2cFD, (unsigned int) add, (unsigned int) length);
	}

	jint* bufferPtr = (*env)->GetIntArrayElements(env, barray, NULL);

	for(i=0; i<length; i++)
	{
		bufferPtr[i] = bytes[i];
	}

	(*env)->ReleaseIntArrayElements(env, barray, bufferPtr, 0);

	return JNI_TRUE;
}

void JAVA_CLASS_PATH(i2cClose)(JNIEnv *env, jobject this, jint i2cFD)
{
	i2cClose(i2cFD) ;

	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "i2cClose(%d) succeeded", (unsigned int) i2cFD);

}

/* End the JNI wrapper funtions for the I2C app */

/* End the JNI wrapper funtions for the SPI app */

jint JAVA_CLASS_PATH(spiOpen)(JNIEnv *env, jobject this, jint bus, jint device, jint speed, jint mode, jint bpw)
{
	jint ret;
	ret = spiOpen(bus, device, speed, mode, bpw) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "spiOpen(%d, %d, %d, %d, %d) failed!", (unsigned int) bus, (unsigned int) device, (unsigned int) speed, (unsigned int) mode, (unsigned int) bpw);
		return -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "spiOpen(%d, %d, %d, %d, %d) succeeded", (unsigned int) bus, (unsigned int) device, (unsigned int) speed, (unsigned int) mode, (unsigned int) bpw);
	}

	return ret;
}

jint JAVA_CLASS_PATH(spiWriteByte)(JNIEnv *env, jobject this, jint spiFD, jbyte data)
{
	jint ret;
	
	unsigned char value = data; 
	unsigned char null = 0x00;
	
	ret = spiTransfer(spiFD, &value, &null, 1);

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "spiWriteByte(%d, %d) failed!", (unsigned int) spiFD, (unsigned int) data);
		return -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "spiWriteByte(%d, %d) succeeded", (unsigned int) spiFD, (unsigned int) data);
	}

	return ret;
}

void JAVA_CLASS_PATH(spiClose)(JNIEnv *env, jobject this, jint spiFD)
{
	spiClose(spiFD) ;

	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "spiClose(%d, bytearray) succeeded", (unsigned int) spiFD);

}

/* End the JNI wrapper funtions for the SPI app */

/* Begin the JNI wrapper functions for the UART app */

jint JAVA_CLASS_PATH(uartOpen)(JNIEnv *env, jobject this, jint device, jint bdrate)
{
	jint ret;
	ret = uartOpen(device, bdrate) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "uartOpen(%d, %d) failed!", (unsigned int) device, (unsigned int) bdrate);
		ret = -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "uartOpen(%d, %d) succeeded", (unsigned int) device, (unsigned int) bdrate);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(uartWrite)(JNIEnv *env, jobject this, jint uartFD, jint length, jbyteArray barray)
{
	jint ret;
	int i;

	jbyte* bufferPtr = (*env)->GetByteArrayElements(env, barray, NULL);

	unsigned char bytes[length] ;

	for(i=0; i<length; i++)
	{
		bytes[i] = bufferPtr[i];
	}

	(*env)->ReleaseByteArrayElements(env, barray, bufferPtr, 0);

	ret = uartWrite(uartFD, length, bytes) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "uartWrite(%d, %d, bytearray) failed!", (unsigned int) uartFD, (unsigned int) length);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "uartWrite(%d, %d, bytearray) succeeded", (unsigned int) uartFD, (unsigned int) length);
	}

	return JNI_TRUE;
}

jboolean JAVA_CLASS_PATH(uartRead)(JNIEnv *env, jobject this, jint uartFD, jint length, jintArray barray)
{
	jint ret;
	int i;
	unsigned char bytes[length] ;

	ret = uartRead(uartFD, length, bytes) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "uartRead(%d, %d, bytearray) failed!", (unsigned int) uartFD, (unsigned int) length);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "uartRead(%d, %d, bytearray) succeeded", (unsigned int) uartFD, (unsigned int) length);
	}

	jint* bufferPtr = (*env)->GetIntArrayElements(env, barray, NULL);

	for(i=0; i<length; i++)
	{
		bufferPtr[i] = bytes[i];
	}

	(*env)->ReleaseIntArrayElements(env, barray, bufferPtr, 0);

	return JNI_TRUE;
}

void JAVA_CLASS_PATH(uartClose)(JNIEnv *env, jobject this, jint uartFD)
{
	uartClose(uartFD) ;

	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "uartClose(%d) succeeded", (unsigned int) uartFD);

}

/* End the JNI wrapper funtions for the UART app */

/* Begin the JNI wrapper functions for the CAN app */

jint JAVA_CLASS_PATH(canOpenRaw)(JNIEnv *env, jobject this, jstring port)
{
	jint ret;

	const char *p;
    p = (*env)->GetStringUTFChars( env, port , NULL ) ;

	ret = canOpenRaw(p) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "canOpenRaw(%s) failed!", p);
		ret = -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "canOpenRaw(%s) succeeded", p);
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(canSendBytes)(JNIEnv *env, jobject this, jint canFD, jint length, jbyteArray barray)
{
	jint ret;
	int i;

	jbyte* bufferPtr = (*env)->GetByteArrayElements(env, barray, NULL);

	unsigned char bytes[length] ;

	for(i=0; i<length; i++)
	{
		bytes[i] = bufferPtr[i];
	}

	(*env)->ReleaseByteArrayElements(env, barray, bufferPtr, 0);

	ret = canSendBytes(canFD, length, bytes) ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "canSendBytes(%d, %d, bytearray) failed!", (unsigned int) canFD, (unsigned int) length);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "canSendBytes(%d, %d, bytearray) succeeded", (unsigned int) canFD, (unsigned int) length);
	}

	return JNI_TRUE;
}

jbyteArray JAVA_CLASS_PATH(canReadBytes)(JNIEnv *env, jobject this, jint canFD)
{
	unsigned char *value ;
	int length;
	value = canReadBytes(canFD, &length) ;

    if(value!=NULL)
    {
    	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "canReadBytes(%d) succeeded", (unsigned int) canFD);
    	
		jbyteArray barray = (*env)->NewByteArray(env, length);
    	(*env)->SetByteArrayRegion(env, barray, 0, length, value);

		return barray;
    }

	return NULL;
}

void JAVA_CLASS_PATH(canClose)(JNIEnv *env, jobject this, jint canFD)
{
	canClose(canFD) ;

	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "canClose(%d) succeeded", (unsigned int) canFD);

}

/* End the JNI wrapper funtions for the CAN app */

/* Begin the JNI wrapper functions for the USB app */

jint JAVA_CLASS_PATH(usbInit)(JNIEnv *env, jobject this)
{
	jint ret;

	ret = usbInit() ;

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "usbInit() failed!");
		ret = -1;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "usbInit() succeeded");
	}

	return ret;
}

jboolean JAVA_CLASS_PATH(usbGetDevices)(JNIEnv *env, jobject this, jobjectArray idArray, jobjectArray stringsArray)
{
	jint ret;
	int i, j;

	int count = (* env)->GetArrayLength(env, idArray);

	unsigned char strings[count][3][256];
	int ids[count][8];
	
	ret = usbGetDevices(ids, strings);

	if ( ret == -1 ) {
		__android_log_print(ANDROID_LOG_ERROR, BBBANDROID_NATIVE_TAG, "usbGetDevices(%d, intarray, bytearray) failed!", count);
		return JNI_FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "usbGetDevices(%d, intarray, bytearray) succeeded", count);
	}

	for(i=0; i<count; i++)
	{
		jarray myidarray = ((* env)->GetObjectArrayElement (env, idArray, i));
		jint* dids = (*env)->GetIntArrayElements(env, myidarray, NULL);

		memcpy(dids, ids[i], sizeof(ids[i]));

		(*env)->ReleaseIntArrayElements(env, myidarray, dids, 0);

		
		jarray mystrsarray = ((* env)->GetObjectArrayElement (env, stringsArray, i));

		jarray mystrarray = ((* env)->GetObjectArrayElement (env, mystrsarray, 0));
		jbyte* dstring = (*env)->GetByteArrayElements(env, mystrarray, NULL);
		memcpy(dstring, strings[i][0], strlen(strings[i][0]));
		(*env)->ReleaseByteArrayElements(env, mystrarray, dstring, 0);

		mystrarray = ((* env)->GetObjectArrayElement (env, mystrsarray, 1));
		dstring = (*env)->GetByteArrayElements(env, mystrarray, NULL);
		memcpy(dstring, strings[i][1], strlen(strings[i][1]));
		(*env)->ReleaseByteArrayElements(env, mystrarray, dstring, 1);

		mystrarray = ((* env)->GetObjectArrayElement (env, mystrsarray, 2));
		dstring = (*env)->GetByteArrayElements(env, mystrarray, NULL);
		memcpy(dstring, strings[i][2], strlen(strings[i][2]));
		(*env)->ReleaseByteArrayElements(env, mystrarray, dstring, 2);
	}
	
	return JNI_TRUE;
}

void JAVA_CLASS_PATH(usbClose)(JNIEnv *env, jobject this)
{
	usbClose() ;

	__android_log_print(ANDROID_LOG_DEBUG, BBBANDROID_NATIVE_TAG, "usbClose() succeeded");

}

/* End the JNI wrapper funtions for the USB app */

/* End the JNI wrapper functions for the Complete app */