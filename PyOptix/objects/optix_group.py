
__author__ = 'vizera-ubuntu'

from PyOptixCpp.Core import _OptixGroupWrapper

from PyOptix.objects.commons.optix_has_child import OptixHasChild
from PyOptix.objects.commons.optix_object import OptixObject

class OptixGroup(_OptixGroupWrapper, OptixObject, OptixHasChild):

    def __init__(self, native, context):
        OptixObject.__init__(self, context, native)
        _OptixGroupWrapper.__init__(self, native)

        from PyOptix.objects.optix_geometry_group import OptixGeometryGroup
        from PyOptix.objects.optix_selector import OptixSelector
        from PyOptix.objects.optix_transform import OptixTransform
        from PyOptix.objects.optix_acceleration import OptixAcceleration
        allowed_children = [OptixGeometryGroup, OptixGroup, OptixSelector, OptixTransform, OptixAcceleration]

        OptixHasChild.__init__(self, allowed_children)