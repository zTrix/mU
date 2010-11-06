#include <mU/System.h>

using namespace mU;

CAPI void VALUE(Context)(Kernel& k, var& r, Tuple& x) {
	if (x.size == 1) {
		r = k.context();
		return;
	}
	if (x.size == 2 && x[1].isSymbol()) {
		r = x[1].symbol()->context;
		return;
	}
}
CAPI void VALUE(ContextPath)(Kernel& k, var& r, Tuple& x) {
	r = mU::list(k.contextPath().size(), k.contextPath().begin());
}
CAPI void VALUE(Begin)(Kernel& k, var& r, Tuple& x) {
	if (x.size == 2 && x[1].isSymbol()) {
		r = boolean(k.beginContext(x[1].symbol()));
		return;
	}
}
CAPI void VALUE(End)(Kernel& k, var& r, Tuple& x) {
	r = boolean(k.endContext());
}
CAPI void VALUE(BeginPackage)(Kernel& k, var& r, Tuple& x) {
	if (x.size == 2 && x[1].isSymbol()) {
		r = boolean(k.beginPackage(x[1].symbol()));
		return;
	}
}
CAPI void VALUE(EndPackage)(Kernel& k, var& r, Tuple& x) {
	r = boolean(k.endPackage());
}