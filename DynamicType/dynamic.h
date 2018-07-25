#pragma once

namespace moon {

	class dynamic {
	private:
		void* ptr_ = nullptr;
		size_t allocatedSize_ = 0;

	public:
		dynamic() {}
		~dynamic() { if (ptr_ != nullptr) delete ptr_; }

		template<typename T>
		dynamic* operator=(T rhs) {
			if (ptr_ != nullptr)
				delete ptr_;
			allocatedSize_ = sizeof(T);
			ptr_ = new T(rhs);
			return this;
		}

		template<typename T>
		T operator*(T rhs) {
			T value = *static_cast<T*>(ptr_);
			ptr_ = new T(value * rhs);
			return value * rhs;
		}

		template<typename T>
		T operator+(T rhs) {
			T value = *static_cast<T*>(ptr_);
			ptr_ = new T(value + rhs);
			return value + rhs;
		}

		template<typename T>
		T operator-(T rhs) {
			T value = *static_cast<T*>(ptr_);
			ptr_ = new T(value - rhs);
			return value - rhs;
		}

		template<typename T>
		T operator/(T rhs) {
			T value = *static_cast<T*>(ptr_);
			ptr_ = new T(value / rhs);
			return value / rhs;
		}

		template<typename T>
		const T& cast() {
			if (ptr_ == nullptr)
				return T();
			T t =  *static_cast<T*>(ptr_);
			return t;
		}

		const size_t size_bytes() {
			return allocatedSize_;
		}


	};
}