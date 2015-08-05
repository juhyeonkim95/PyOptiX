#ifndef ENUMS_PACKAGE_H
#define ENUMS_PACKAGE_H

#include "Python.h"
#include <boost/python.hpp>
#include <boost/numpy.hpp>

#include "optix_shared_includes.h"

void export_enums_package()
{
    namespace bp = boost::python;

    bp::object enums_module(bp::handle<>(bp::borrowed(PyImport_AddModule("PyOptixCpp.Enums"))));
    bp::scope().attr("Enums") = enums_module;
    bp::scope enums_scope = enums_module;

    //BUFFER
    bp::enum_<RTformat>("RTformat")
        .value("RT_FORMAT_UNKNOWN", RT_FORMAT_UNKNOWN)
        .value("RT_FORMAT_FLOAT", RT_FORMAT_FLOAT)
        .value("RT_FORMAT_FLOAT2", RT_FORMAT_FLOAT2)
        .value("RT_FORMAT_FLOAT3", RT_FORMAT_FLOAT3)
        .value("RT_FORMAT_FLOAT4", RT_FORMAT_FLOAT4)
        .value("RT_FORMAT_BYTE", RT_FORMAT_BYTE)
        .value("RT_FORMAT_BYTE2", RT_FORMAT_BYTE2)
        .value("RT_FORMAT_BYTE3", RT_FORMAT_BYTE3)
        .value("RT_FORMAT_BYTE4", RT_FORMAT_BYTE4)
        .value("RT_FORMAT_UNSIGNED_BYTE", RT_FORMAT_UNSIGNED_BYTE)
        .value("RT_FORMAT_UNSIGNED_BYTE2", RT_FORMAT_UNSIGNED_BYTE2)
        .value("RT_FORMAT_UNSIGNED_BYTE3", RT_FORMAT_UNSIGNED_BYTE3)
        .value("RT_FORMAT_UNSIGNED_BYTE4", RT_FORMAT_UNSIGNED_BYTE4)
        .value("RT_FORMAT_SHORT", RT_FORMAT_SHORT)
        .value("RT_FORMAT_SHORT2", RT_FORMAT_SHORT2)
        .value("RT_FORMAT_SHORT3", RT_FORMAT_SHORT3)
        .value("RT_FORMAT_SHORT4", RT_FORMAT_SHORT4)
        .value("RT_FORMAT_UNSIGNED_SHORT", RT_FORMAT_UNSIGNED_SHORT)
        .value("RT_FORMAT_UNSIGNED_SHORT2", RT_FORMAT_UNSIGNED_SHORT2)
        .value("RT_FORMAT_UNSIGNED_SHORT3", RT_FORMAT_UNSIGNED_SHORT3)
        .value("RT_FORMAT_UNSIGNED_SHORT4", RT_FORMAT_UNSIGNED_SHORT4)
        .value("RT_FORMAT_INT", RT_FORMAT_INT)
        .value("RT_FORMAT_INT2", RT_FORMAT_INT2)
        .value("RT_FORMAT_INT3", RT_FORMAT_INT3)
        .value("RT_FORMAT_INT4", RT_FORMAT_INT4)
        .value("RT_FORMAT_UNSIGNED_INT", RT_FORMAT_UNSIGNED_INT)
        .value("RT_FORMAT_UNSIGNED_INT2", RT_FORMAT_UNSIGNED_INT2)
        .value("RT_FORMAT_UNSIGNED_INT3", RT_FORMAT_UNSIGNED_INT3)
        .value("RT_FORMAT_UNSIGNED_INT4", RT_FORMAT_UNSIGNED_INT4)
        .value("RT_FORMAT_USER", RT_FORMAT_USER)
        .value("RT_FORMAT_BUFFER_ID", RT_FORMAT_BUFFER_ID)
        .value("RT_FORMAT_PROGRAM_ID", RT_FORMAT_PROGRAM_ID);

    bp::enum_<RTbuffertype>("RTbuffertype")
        .value("RT_BUFFER_INPUT", RT_BUFFER_INPUT)
        .value("RT_BUFFER_OUTPUT", RT_BUFFER_OUTPUT)
        .value("RT_BUFFER_INPUT_OUTPUT", RT_BUFFER_INPUT_OUTPUT);

    bp::enum_<RTbufferflag>("RTbufferflag")
        .value("RT_BUFFER_GPU_LOCAL", RT_BUFFER_GPU_LOCAL)
        .value("RT_BUFFER_COPY_ON_DIRTY", RT_BUFFER_COPY_ON_DIRTY);

    //TEXTURE
    bp::enum_<RTwrapmode>("RTwrapmode")
        .value("RT_WRAP_REPEAT", RT_WRAP_REPEAT)
        .value("RT_WRAP_CLAMP_TO_EDGE", RT_WRAP_CLAMP_TO_EDGE)
        .value("RT_WRAP_MIRROR", RT_WRAP_CLAMP_TO_EDGE)
        .value("RT_WRAP_CLAMP_TO_BORDER", RT_WRAP_CLAMP_TO_EDGE);

    bp::enum_<RTfiltermode>("RTfiltermode")
        .value("RT_FILTER_NEAREST", RT_FILTER_NEAREST)
        .value("RT_FILTER_LINEAR", RT_FILTER_LINEAR)
        .value("RT_FILTER_NONE", RT_FILTER_NONE);

    bp::enum_<RTtexturereadmode>("RTtexturereadmode")
        .value("RT_TEXTURE_READ_ELEMENT_TYPE", RT_TEXTURE_READ_ELEMENT_TYPE)
        .value("RT_TEXTURE_READ_NORMALIZED_FLOAT", RT_TEXTURE_READ_NORMALIZED_FLOAT);

    bp::enum_<RTtextureindexmode>("RTtextureindexmode")
        .value("RT_TEXTURE_INDEX_NORMALIZED_COORDINATES", RT_TEXTURE_INDEX_NORMALIZED_COORDINATES)
        .value("RT_TEXTURE_INDEX_ARRAY_INDEX", RT_TEXTURE_INDEX_ARRAY_INDEX);

    bp::enum_<RTexception>("RTexception")
        .value("RT_EXCEPTION_PROGRAM_ID_INVALID", RT_EXCEPTION_PROGRAM_ID_INVALID)
        .value("RT_EXCEPTION_TEXTURE_ID_INVALID", RT_EXCEPTION_TEXTURE_ID_INVALID)
        .value("RT_EXCEPTION_BUFFER_ID_INVALID", RT_EXCEPTION_BUFFER_ID_INVALID)
        .value("RT_EXCEPTION_INDEX_OUT_OF_BOUNDS", RT_EXCEPTION_INDEX_OUT_OF_BOUNDS)
        .value("RT_EXCEPTION_STACK_OVERFLOW", RT_EXCEPTION_STACK_OVERFLOW)
        .value("RT_EXCEPTION_BUFFER_INDEX_OUT_OF_BOUNDS", RT_EXCEPTION_BUFFER_INDEX_OUT_OF_BOUNDS)
        .value("RT_EXCEPTION_INVALID_RAY", RT_EXCEPTION_INVALID_RAY)
        .value("RT_EXCEPTION_INTERNAL_ERROR", RT_EXCEPTION_INTERNAL_ERROR)
        .value("RT_EXCEPTION_USER", RT_EXCEPTION_USER)
        .value("RT_EXCEPTION_ALL ", RT_EXCEPTION_ALL);

    bp::enum_<RTobjecttype>("RTobjecttype")
        .value("RT_OBJECTTYPE_UNKNOWN", RT_OBJECTTYPE_UNKNOWN)
        .value("RT_OBJECTTYPE_GROUP", RT_OBJECTTYPE_GROUP)
        .value("RT_OBJECTTYPE_GEOMETRY_GROUP", RT_OBJECTTYPE_GEOMETRY_GROUP)
        .value("RT_OBJECTTYPE_TRANSFORM", RT_OBJECTTYPE_TRANSFORM)
        .value("RT_OBJECTTYPE_SELECTOR", RT_OBJECTTYPE_SELECTOR)
        .value("RT_OBJECTTYPE_GEOMETRY_INSTANCE", RT_OBJECTTYPE_GEOMETRY_INSTANCE)
        .value("RT_OBJECTTYPE_BUFFER", RT_OBJECTTYPE_BUFFER)
        .value("RT_OBJECTTYPE_TEXTURE_SAMPLER", RT_OBJECTTYPE_TEXTURE_SAMPLER)
        .value("RT_OBJECTTYPE_OBJECT", RT_OBJECTTYPE_OBJECT)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT2x2", RT_OBJECTTYPE_MATRIX_FLOAT2x2)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT2x3", RT_OBJECTTYPE_MATRIX_FLOAT2x3)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT2x4", RT_OBJECTTYPE_MATRIX_FLOAT2x4)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT3x2", RT_OBJECTTYPE_MATRIX_FLOAT3x2)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT3x3", RT_OBJECTTYPE_MATRIX_FLOAT3x3)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT3x4", RT_OBJECTTYPE_MATRIX_FLOAT3x4)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT4x2", RT_OBJECTTYPE_MATRIX_FLOAT4x2)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT4x3", RT_OBJECTTYPE_MATRIX_FLOAT4x3)
        .value("RT_OBJECTTYPE_MATRIX_FLOAT4x4", RT_OBJECTTYPE_MATRIX_FLOAT4x4)
        .value("RT_OBJECTTYPE_FLOAT", RT_OBJECTTYPE_FLOAT)
        .value("RT_OBJECTTYPE_FLOAT2", RT_OBJECTTYPE_FLOAT2)
        .value("RT_OBJECTTYPE_FLOAT3", RT_OBJECTTYPE_FLOAT3)
        .value("RT_OBJECTTYPE_FLOAT4", RT_OBJECTTYPE_FLOAT4)
        .value("RT_OBJECTTYPE_INT", RT_OBJECTTYPE_INT)
        .value("RT_OBJECTTYPE_INT2", RT_OBJECTTYPE_INT2)
        .value("RT_OBJECTTYPE_INT3", RT_OBJECTTYPE_INT3)
        .value("RT_OBJECTTYPE_INT4", RT_OBJECTTYPE_INT4)
        .value("RT_OBJECTTYPE_UNSIGNED_INT", RT_OBJECTTYPE_UNSIGNED_INT)
        .value("RT_OBJECTTYPE_UNSIGNED_INT2", RT_OBJECTTYPE_UNSIGNED_INT2)
        .value("RT_OBJECTTYPE_UNSIGNED_INT3", RT_OBJECTTYPE_UNSIGNED_INT3)
        .value("RT_OBJECTTYPE_UNSIGNED_INT4", RT_OBJECTTYPE_UNSIGNED_INT4)
        .value("RT_OBJECTTYPE_USER", RT_OBJECTTYPE_USER)
        .value("RT_OBJECTTYPE_PROGRAM", RT_OBJECTTYPE_PROGRAM);
}





#endif
