float2 p = 5*tcord-1;
//p.y *= resolution.y / resolution.x;
float3 pos= cpos;
float fm =1;///tan(90*3.1415/180);
float3 cvecz=normalize(cpos);
float3 cvecx = normalize(cross(float3(10,0,0),cvecz));
float3 cvecy = cross(cvecz, cvecx);
float3 ray = cvec;//normalize(p.x*cvecy + p.y*cvecz + fm*cvecx);////normalize(p.x*cvecy + p.y*cvecz + fm*cvecx);
float step = 0.01;
float u= 100*c1*hsize/length(pos),old_u;
float u0=u;
float3 normal_vec=normalize(pos);
float3 tangent_vec=normalize(cross(cross(normal_vec,ray),normal_vec));
 float du = dot(ray,normal_vec) / dot(ray,tangent_vec)*u;
 float du0 = du;
 float phi = 0.0;
float t = time;
float dt=1;
float opa=0;
float3 old_pos;
float3 color= float3(0,0,0);
	   for (int i=0; i < nstep; i++) {
	   

        step = maxrot * 2.0*3.1459 / float(nstep);
		float max_rel_u_change = (1.0-log(u*2.5))*10.0 / float(nstep);
		if ((du >0 || (du0 < 0.0 && u0/u < 100)) && abs(du) > abs(max_rel_u_change*u) / step)
            step = max_rel_u_change*u/abs(du);
			old_u = u;
			u += du*step;
			float ddu = -u*(1.0 - 1.5*u*u);
        du += ddu*step;
		if (u < 0.0) break;

        phi -= step;
		old_pos = pos;
        pos = c1*(cos(phi)*normal_vec + sin(phi)*tangent_vec)/u;
		ray = pos-old_pos;
		
        
		
	
		
		
		
		
		//old_pos+=ray*-1.5; 
		
		if ((old_pos.z )* (pos.z) < 0) {
            // crossed plane z=0
			
			
			
            float acc_isec_t = abs( (old_pos.z) / ray.z);
            if (acc_isec_t < 1) {
                float3 isec = float3(old_pos.x,old_pos.y,old_pos.z) + ray*acc_isec_t;

                float r = length(isec);

                if (r < rradmin) {
                    float2 tex_coord = float2(
                            (r-rradmin)*rv/(rwidth+(nval/r)),
                            (atan2(isec.x, isec.y)/3.1459*0.5)+0.5+ tval + rint/r 
                    );
					float ray_l = length(ray)/(thresh*c1);
                    float accretion_intensity = 0.9;
                    //accretion_intensity *= 1.0 / abs(ray.z/ray_l);
                    float temperature = 3900;

                    float3 accretion_v = float3(-isec.y, isec.x, 0.0) / sqrt(2.0*(r-1.0)) / (r*r);
                    float gamma = (1.0)/sqrt(1.0-dot(accretion_v,accretion_v));
                    float doppler_factor = gamma*(1.0+dot(ray/ray_l,accretion_v));
                    
                    accretion_intensity /= doppler_factor*doppler_factor*doppler_factor;
                    
                    
                    temperature /= doppler_factor*3500;
                     
	
                    color += ad.SampleLevel(adSampler,tex_coord,  0)*lerp(v1/1.65,v2*1.65,temperature)
                        * accretion_intensity*(iring/exp(r*str))
                        ;
						if (length(color)>0.3)
						{
						break;
						}
                }
            }
        }
		
		
			
        if (u > 1) {
		opa=1;
		break; }
		
		
		
		
		if (u < 1.0) {
        ray = normalize(pos - old_pos);
		}
		}
		
		
		

return  	float4(color,opa);;
    


