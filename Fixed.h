typedef int32_t s32;
typedef uint32_t u32;

typedef int64_t s64;
typedef uint64_t u64;

class f32
{
public:
	s32 Fixed;

	inline f32(float n)
	{
		Fixed = ((s32)((n) * (1 << 12)));
	}

	inline float Float()
	{
		return (((float)(Fixed)) / (float)(1 << 12));
	}

	inline void operator+=(f32 const& n)
	{
		Fixed += n.Fixed;
	}

	inline void operator+=(float const& n)
	{
		Fixed += f32(n).Fixed;
	}

	inline void operator-=(f32 const& n)
	{
		Fixed -= n.Fixed;
	}

	inline void operator-=(float const& n)
	{
		Fixed -= f32(n).Fixed;
	}


	inline f32 operator+(f32 const& n)
	{
		return Fixed + n.Fixed;
	}

	inline f32 operator+(float const& n)
	{
		return Fixed + f32(n).Fixed;
	}

	inline f32 operator-(f32 const& n)
	{
		return Fixed - n.Fixed;
	}

	inline f32 operator-(float const& n)
	{
		return Fixed - f32(n).Fixed;
	}

	//for the ds use hardware assisted math func like mul32f() or divf32()
	inline void operator*=(f32 const& n)
	{
		Fixed = ((s64)Fixed * (s64)n.Fixed) >> 12;
	}

	inline void operator*=(float const& n)
	{
		Fixed = ((s64)Fixed * (s64)f32(n).Fixed) >> 12;
	}

	inline void operator/=(f32 const& n)
	{
		Fixed = ((s64)Fixed << 12) / (s64)n.Fixed;
	}

	inline void operator/=(float const& n)
	{
		Fixed = ((s64)Fixed << 12) / (s64)f32(n).Fixed;
	}


	inline f32 operator*(f32 const& n)
	{
		return ((s64)Fixed * (s64)n.Fixed) >> 12;
	}

	inline f32 operator*(float const& n)
	{
		return ((s64)Fixed * (s64)f32(n).Fixed) >> 12;
	}

	inline f32 operator/(f32 const& n)
	{
		return ((s64)Fixed << 12) / (s64)n.Fixed;
	}

	inline f32 operator/(float const& n)
	{
		return ((s64)Fixed << 12) / (s64)f32(n).Fixed;
	}
};