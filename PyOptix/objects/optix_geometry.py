from PyOptix.objects.commons.optix_scoped_object import OptixScopedObject

__author__ = 'vizera-ubuntu'

from PyOptixCpp.Core import _OptixGeometryWrapper

from PyOptix.objects.commons.optix_object import OptixObject

class OptixGeometry(_OptixGeometryWrapper, OptixObject, OptixScopedObject):

    def __init__(self, native, context):
        OptixObject.__init__(self, context, native)
        _OptixGeometryWrapper.__init__(self, native)
        OptixScopedObject.__init__(self)
